#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct Queue {
    int f, r, size;
    int* A;
}queue;

int isEmpty(queue* q);
int isFull(queue* q);
void initQueue(queue* q, int n);
void enqueue(queue* q, int data);
void dequeue(queue* q);
void print_Q(queue* q);

void main() {
    int q_size, n, e;
    char c;
    queue* q = (queue*)malloc(sizeof(queue));

    scanf("%d", &q_size);
    initQueue(q, q_size);

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);

        switch (c) {

            case 'I':
                scanf("%d", &e);
                if (isFull(q) == 1)
                {
                    printf("overflow");
                    print_Q(q);
                    return;
                }
                enqueue(q, e);
                break;
            case 'D':
                if (isEmpty(q) == 1) {
                    printf("underflow\n");
                    return;
                }
                dequeue(q);
                break;
            case 'P':
                print_Q(q);
                break;
        }

        getchar();
    }
}


int isEmpty(queue* q)
{
    if (q->f == (q->r) % q->size)
        return 1;
    return 0;
}

int isFull(queue* q)
{
    if (q->f == (q->r + 1) % q->size)
        return 1;
    return 0;
}

void initQueue(queue* q, int n)
{
    q->f = 0;
    q->r = 0;
    q->size = n;
    q->A = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        q->A[i] = 0;
    }
}

void enqueue(queue* q, int data)
{
    q->r = ((q->r) + 1) % (q->size);
    q->A[q->r] = data;
    return;
}

void dequeue(queue* q)
{
    q->f = (q->f + 1) % q->size;
    q->A[q->f] = 0;
    return;
}

void print_Q(queue* q)
{
    for (int i = 0; i < q->size; i++) {
        printf(" %d", q->A[i]);
    }
    printf("\n");
}
