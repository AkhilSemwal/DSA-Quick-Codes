#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, char c) { s->items[++(s->top)] = c; }
char pop(Stack *s) { return s->items[(s->top)--]; }
char peek(Stack *s) { return s->items[s->top]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverseStr(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

/* Infix to Prefix Conversion */
void infixToPrefix(const char *infix, char *prefix) {
    char revInfix[MAX];
    strcpy(revInfix, infix);
    reverseStr(revInfix);
    
    // Swap '(' with ')' and vice versa
    for (int i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(') revInfix[i] = ')';
        else if (revInfix[i] == ')') revInfix[i] = '(';
    }
    
    Stack s;
    init(&s);
    char postfix[MAX];
    int k = 0;
    
    for (int i = 0; revInfix[i] != '\0'; i++) {
        char ch = revInfix[i];
        
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s)) pop(&s);
        } else {
            while (!isEmpty(&s) && peek(&s) != '(' && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
    
    // Reverse postfix to get final prefix
    strcpy(prefix, postfix);
    reverseStr(prefix);
}

int main() {
    printf("=== Infix to Prefix Conversion using Stack ===\n\n");
    
    const char *expressions[] = {
        "(A-B/C)*(A/K-L)",
        "A+B*C-D/E",
        "(A+B)*C-(D-E)*(F+G)"
    };
    
    char prefix[MAX];
    int n = sizeof(expressions) / sizeof(expressions[0]);
    
    for (int i = 0; i < n; i++) {
        infixToPrefix(expressions[i], prefix);
        printf("Infix  : %s\n", expressions[i]);
        printf("Prefix : %s\n\n", prefix);
    }
    
    return 0;
}
