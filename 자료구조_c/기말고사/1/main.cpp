#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct Node {
    struct Node* next;
    int data;
}Node;

typedef struct queue {
    Node* front;
    Node* rear;
}queue;

int isEmpty(queue* q);
void input(queue* q, int e);
int print(queue* q);
void display_P(queue* q);


Node* getNode() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = NULL;
    return newNode;
}

queue* initqueue(Node* x) {
    queue* newqueue;

    newqueue = (queue*)malloc(sizeof(queue));

    newqueue->front = x;
    newqueue->rear = x;

    return newqueue;
}

void main() {
    Node* x = getNode();
    queue* q = initqueue(x);
    char str[10];
    int n, e;

    while (1) {
        printf("[1] 프린트할 묶음의 장수 입력 [2] 프린트 출력 시 나오는 묶음의 장수 [3]현재 남아있는 프린트들 묶음 장수 보기 [4] 종료 \n");
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &e);
            input(q, e);
        }
        else if (n == 2) {
            printf("%d\n", print(q));
        }
        else if (n == 3)
            display_P(q);
        else
            break;
    }
}

int isEmpty(queue* q)
{
    if (q->front->data == NULL && q->rear->data == NULL)
        return 1;
}

void input(queue* q, int e)
{
    Node* newNode = getNode();

    newNode->data = e;

    if (isEmpty(q) == 1) {
        newNode->data = e;
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int print(queue* q)
{
    int e;
    Node* p = getNode();

    if (isEmpty(q) == 1) {
        printf("남아있는 명령이 없습니다.");
    }
    else {
        e = q->front->data;
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;
        return e;
    }
}
void display_P(queue* q)
{
    Node* p = getNode();
    p = q->front;
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}
