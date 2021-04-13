#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Stack {
    char A[100];
    int top, Max_Size;
}stack;
void initStack(stack* s, int size);
void push(stack* s, char item);
char pop(stack* s);
char peek(stack* s);
void duplicate(stack* s);
void upRotate(stack* s, int n);
void downRotate(stack* s, int n);
void print(stack* s);
int main() {
    int size, n, elem;
    stack *S;
    S = (stack*)malloc(sizeof(stack));
    char item, str[10];
    scanf("%d", &size);
    initStack(S, size);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        getchar();
        if (strcmp(str, "POP") == 0)
            pop(S);
        else if (strcmp(str, "PUSH") == 0) {
            scanf("%c", &item);
            getchar();
            push(S, item);
        }
        else if (strcmp(str, "PEEK") == 0) {
            printf("%c\n",peek(S));
        }
        else if (strcmp(str, "DUP") == 0) {
            duplicate(S);
        }
        else if (strcmp(str, "UpR") == 0) {
            scanf("%d", &elem);
            upRotate(S, elem);
        }
        else if (strcmp(str, "DownR") == 0) {
            scanf("%d\n", &elem);
            downRotate(S, elem);
        }
        else
            print(S);
    }
}
void initStack(stack* s,int size) {
    s->top = -1;
    s->Max_Size = size;
}
void push(stack* s, char item) {
    if (s->top >= (s->Max_Size)- 1) {
        printf("Stack FULL\n");
        return;
    }
    s->A[++(s->top)] = item;
    return;
}
char pop(stack* s) {
    if (s->top == -1) {
        printf("Stack Empty\n");
        return'\0';
    }
    return s->A[(s->top)--];
}
char peek(stack* s) {
    if (s->top == -1) {
        printf("Stack Empty\n");
        return'\0';
    }
    return s->A[(s->top)];
}
void duplicate(stack* s) {
    char c;
    if (s->top >= s->Max_Size - 1) {
        printf("Stack FULL\n");
        return;
    }
    c = pop(s);
    push(s, c);
    push(s, c);
}
void upRotate(stack* s, int n) {
    char tmp;
    if (n > s->top+1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        tmp = s->A[(s->top) - i];
        s->A[(s->top) - i] = s->A[(s->top) - (i + 1)];
        s->A[(s->top) - (i + 1)] = tmp;
    }
}
void downRotate(stack* s, int n) {
    char tmp,c;
    if (n > s->top+1)
        return;
    c = s->A[(s->top)-n+1];
    for (int i = n-1; i >0; i--)
    {
        s->A[(s->top) - i] = s->A[(s->top) - i+1];
    }
    s->A[s->top] = c;
}
void print(stack* s) {
    int cnt = s->top;

    while (1) {
        if (cnt == -1)
            break;
        printf("%c", s->A[cnt--]);
    }
    printf("\n");
}