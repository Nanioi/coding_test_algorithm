#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Stack {
    int A[100];
    int top;
}stack;

void initStack(stack* s);
void push(stack* s, int item);
int pop(stack* s);
int evaluate(char *str);
int doOperator(char c, int b, int a);

int main() {
    char str[100];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        printf("%d\n", evaluate(str));
    }
}
void initStack(stack* s) {
    s->top = -1;
}
void push(stack* s, int item) {
    s->A[++(s->top)] = item;
    return;
}
int pop(stack* s) {
    return s->A[(s->top)--];
}

int evaluate(char *str) {

    stack* s = (stack*)malloc(sizeof(stack));
    initStack(s);
    int a, b,n,len;
    len = strlen(str);
    for(int i=0;i<len;i++){
        if (str[i]== '+' ||str[i]== '-' ||str[i] == '*' || str[i]== '/') {
            b = pop(s);
            a = pop(s);
            push(s,doOperator(str[i], a, b));
        }
        else
        {
            n = str[i]- '0';
            push(s, n);
        }
    }
    return pop(s);
}
int doOperator(char c, int a, int b) {

    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}
