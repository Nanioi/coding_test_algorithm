#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Stack {
    char A[100];
    int top;
}stack;

void initStack(stack* s);
void push(stack* s, char item);
char pop(stack* s);
int main() {
    char *str;
    stack* s = (stack*)malloc(sizeof(stack));
    int len, flag = 0, i = 0;

    initStack(s);

    scanf("%d", &len);
    str = (char*)malloc(sizeof(char) * len);
    scanf("%s", str);

    for (i = 0; i < len / 2; i++) {
        push(s, str[i]);
    }
    if (len % 2 == 0) {

        for (int i = len / 2;i < len;i++) {
            if (pop(s) != str[i])
                flag = 1;
        }
    }
    else {
        for (int i = (len / 2) + 1;i < len;i++) {
            if (pop(s) != str[i])
                flag = 1;
        }
    }
    if (flag == 1)
        printf("회문 아님");

    else
        printf("회문 임");
}
void initStack(stack* s) {
    s->top = -1;
}
void push(stack* s, char item) {
    s->A[++(s->top)] = item;
    return;
}
char pop(stack* s) {
    if (s->top == -1) {
        printf("Stack Empty\n");
    }
    return s->A[(s->top)--];
}
