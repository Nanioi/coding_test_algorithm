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
void convert(char* str);
int Priority(char c,int idx);

int main() {
    int n;
    char str[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        convert(str);
        printf("\n");
    }
}
void initStack(stack* s) {
    s->top = -1;
}
void push(stack* s, char item) {
    s->A[++(s->top)] = item;
}
char pop(stack* s) {
    return s->A[(s->top)--];
}
void convert(char* str) {
    stack* s = (stack*)malloc(sizeof(stack));
    initStack(s);
    int len,P,pidx;
    len = strlen(str);
    char tmp;

    for (int i = 0; i < len; i++) {

        if (str[i] >= 'A' && str[i] <= 'Z')
            printf("%c", str[i]);
        else if (str[i] == '(') {
            push(s, str[i]);
            pidx = i;
        }
        else if (str[i] == ')') {
            while (s->A[s->top] != '(')
            {
                tmp = pop(s);
                if (tmp == '&' || tmp == '|')
                    printf("%c", tmp);
                printf("%c", tmp);
            }
            tmp = pop(s);
        }
        else {
            if (str[i] == '+' || str[i] == '-')
            {
                if (i==0|| str[i-1]== '*' || str[i - 1] == '/' || str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '(' || str[i - 1] == '&' || str[i - 1] == '|' || str[i - 1] == '!' || str[i - 1] == '>' || str[i - 1] == '<')
                    P = 6;
                else
                    P= Priority(str[i],i);
            }
            else P= Priority(str[i],i);

            while (s->top > -1 && (P <= Priority(s->A[s->top],pidx))){
                tmp = pop(s);
                printf("%c", tmp);
                if (tmp == '&' || tmp == '|') {
                    printf("%c", tmp);
                }
            }

            push(s, str[i]);
            pidx = i;
            if (str[i] == '&' || str[i] == '|') {
                i++;
            }
        }
    }

    while (s->top > -1)
    {
        tmp = pop(s);
        printf("%c", tmp);
        if (tmp == '&' || tmp == '|')
            printf("%c", tmp);
    }
}

int Priority(char c,int idx) {
    switch (c)
    {
        case '+':case '-':{
            if (idx == 0)
                return 6;
            else
                return 4;
            break;
        }
        case '*':case '/': {
            return 5;
            break;
        }
        case '>':case'<': {
            return 3;
            break;
        }
        case '&': {
            return 2;
            break;
        }
        case '|': {
            return 1;
            break;
        }
        case '!': {
            return 6;
            break;
        }
        default:
            return 0;
    }
}