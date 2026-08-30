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

/* Operator Precedence */
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

/* Infix to Postfix Conversion (Shunting-Yard Algorithm) */
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    init(&s);
    int k = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If operand, add directly to output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s)) pop(&s); // Remove '('
        } else { // Operator
            while (!isEmpty(&s) && peek(&s) != '(' &&
                   (precedence(peek(&s)) > precedence(ch) ||
                   (precedence(peek(&s)) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    printf("=== Infix to Postfix Conversion using Stack ===\n\n");
    
    const char *expressions[] = {
        "a+b*(c^d-e)^(f+g*h)-i",
        "(A+B)*C-(D-E)*(F+G)",
        "K+L-M*N+(O^P)*W/U/V*T+Q"
    };
    
    char output[MAX];
    int n = sizeof(expressions) / sizeof(expressions[0]);
    
    for (int i = 0; i < n; i++) {
        infixToPostfix(expressions[i], output);
        printf("Infix   : %s\n", expressions[i]);
        printf("Postfix : %s\n\n", output);
    }
    
    return 0;
}
