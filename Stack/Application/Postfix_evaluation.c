#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

int postfixEvaluation(char *expr) {
    Stack s;
    s.top = -1;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            push(&s, expr[i] - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (expr[i]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
    }
    return s.arr[s.top];
}

int main() {
    printf("=== Postfix Expression Evaluation ===\n");
    
    printf("'23+': %d\n", postfixEvaluation("23+"));
    printf("'23*45+*': %d\n", postfixEvaluation("23*45+*"));
    printf("'56*': %d\n", postfixEvaluation("56*"));
    
    return 0;
}
