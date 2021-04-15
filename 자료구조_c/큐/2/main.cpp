#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct Node {
    struct Node *next,*prev;
    int data;
}Node;

typedef struct deque {
    Node* front;
    Node* rear;
}deque;

int isEmpty(deque* q);
void add_front(deque* q, int e);
void add_rear(deque* q, int e);
int delete_front(deque* q);
int delete_rear(deque* q);
void print(deque* q);


Node* getNode() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = NULL;
    return newNode;
}

deque* initdeque(Node* x) {
    deque* newqueue;

    newqueue = (deque*)malloc(sizeof(deque));

    newqueue->front = x;
    newqueue->rear = x;

    return newqueue;
}

void main() {
    Node* x = getNode();
    deque* q = initdeque(x);
    char str[10];
    int n,e;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (strcmp(str, "AF") == 0) {
            scanf("%d", &e);
            add_front(q, e);
        }
        else if (strcmp(str, "AR") == 0) {
            scanf("%d", &e);
            add_rear(q, e);
        }
        else if (strcmp(str, "DF") == 0) {
            if (isEmpty(q) == 1) {
                printf("underflow\n");
                return;
            }
            delete_front(q);
        }
        else if (strcmp(str, "DR") == 0) {
            if (isEmpty(q) == 1) {
                printf("underflow\n");
                return;
            }
            delete_rear(q);
        }
        else
            print(q);
    }
}

int isEmpty(deque* q)
{
    if (q->front->data == NULL && q->rear->data == NULL)
        return 1;
}

void add_front(deque* q, int e)
{
    Node* newNode = getNode();
    Node* p = q->front;

    newNode->data = e;

    if (p->data == NULL) {
        p->data = e;
    }
    else {
        p->prev = newNode;
        newNode->next=p;
        q->front = newNode;
    }
}

void add_rear(deque* q, int e)
{
    Node* newNode = getNode();
    Node* p = q->rear;

    newNode->data = e;

    if (p->data == NULL) {
        p->data = e;
    }
    else {
        p->next = newNode;
        newNode->prev = p;
        q->rear = newNode;
    }
}

int delete_front(deque* q)
{
    int e;
    e = q->front->data;
    q->front->data = 0;
    q->front = q->front->next;
    return e;
}

int delete_rear(deque* q)
{
    int e;
    e = q->rear->data;
    q->rear->data = 0;
    q->rear = q->rear->prev;
    q->rear->next = NULL;
    return e;
}

void print(deque* q)
{
    Node* p;
    p = q->front;
    while (p!=NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}
