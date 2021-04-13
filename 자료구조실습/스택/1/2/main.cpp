#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Stack {
    char A[100];
    int top;
}stack;

void initStack(stack* s);
int is_open(char item);
int is_counter(char item, char item2);
void push(stack* s, char item);
void pop(stack* s);
int main() {
    char str[1000];
    stack* s = (stack *)malloc(sizeof(stack));
    int len,cnt=0;

    initStack(s);
    gets(str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (is_open(str[i]) == 1) {
            push(s, str[i]);
            cnt++;
        }
        else {
            if (is_counter(str[i], s->A[s->top]) == 1)
            {
                pop(s);
                cnt++;
            }
            else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
                cnt++;
        }
    }
    if (s->top != -1 || cnt%2==1)
        printf("Wrong_%d", cnt);
    else
        printf("OK_%d", cnt);
}
void initStack(stack* s) {
    s->top = -1;
}
int is_open(char item) {
    char open[] = "({[";
    int i;
    int len = strlen(open);

    for (int i = 0; i < len; i++) {
        if (open[i] == item)
            return 1;
    }
    return 0;
}
int is_counter(char item, char item2) {
    if (item2 == '(' && item == ')')
        return 1;
    else if (item2 == '{' && item == '}')
        return 1;
    else if (item2 == '[' && item == ']')
        return 1;
    else
        return 0;
}
void push(stack* s, char item) {
    s->A[++(s->top)] = item;
    return;
}
void pop(stack* s) {
    if (s->top == -1) {
        printf("Stack Empty\n");
    }
    s->top--;
}
