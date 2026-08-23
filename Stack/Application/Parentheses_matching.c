#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void push(Stack *s, char value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isBalanced(const char *expr) {
    Stack s;
    s.top = -1;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) return 0;
            char top = pop(&s);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    printf("=== Parentheses Matching ===\n");
    
    const char *exprs[] = {
        "(a+b)*c",
        "{[()]}",
        "((a+b)",
        "([)]",
        NULL
    };
    
    for (int i = 0; exprs[i] != NULL; i++) {
        printf("'%s': %s\n", exprs[i], isBalanced(exprs[i]) ? "Balanced" : "Not Balanced");
    }
    
    return 0;
}
