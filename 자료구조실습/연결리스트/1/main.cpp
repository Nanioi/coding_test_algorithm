#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev, *next;
    char data;
    int elem;
}node;
void initList(node **H, node **T);
node *newNode();
void addN(node *H, int r,char e);
void DeleteN(node *H, int r);
void getN(node *H, int r);
void PrintL(node *H);
int main() {
    node *H,*T,*p;
    int n,i,r;
    char c,e;
    initList(&H, &T);
    scanf("%d", &n);
    getchar();
    for (i = 0;i < n;i++) {
        scanf("%c", &c);
        switch (c) {
            case 'A':
                scanf("%d %c", &r, &e);
                addN(H, r, e);
                break;
            case 'D':
                scanf("%d", &r);
                DeleteN(H, r);
                break;
            case 'G':
                scanf("%d", &r);
                getN(H, r);
                break;
            case 'P':
                PrintL(H);
                printf("\n");
                break;
        }
        getchar();
    }

    p = H;
    while (p != NULL) {
        p = H->next;
        free(H);
        H = p;
    }

}

void initList(node ** H, node ** T)
{
    (*H) = newNode();
    (*T) = newNode();
    (*H)->next = *T;
    (*T)->prev = *H;
    (*H)->elem= 1;
}

node *newNode()
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->prev = NULL;
    p->next = NULL;

    return p;
}

void addN(node * H, int r,char e)
{
    node *p,*q;
    p = H;
    q=newNode();
    if (r < 1 || r>H->elem)
    {
        printf("invalid position\n");
        return;
    }
    for (int i = 0;i < r;i++) {
        p = p->next;
    }
    q->data = e;
    q->prev = p->prev;
    (p->prev)->next = q;
    q->next = p;
    p->prev = q;
    H->elem = H->elem+1;
}

void DeleteN(node * H, int r)
{
    node *p;
    p = H;
    if (r < 1 || r>=H->elem)
    {
        printf("invalid position\n");
        return;
    }
    for (int i = 0;i < r;i++) {
        p = p->next;
    }
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p);
    H->elem = H->elem - 1;
}
void getN(node * H, int r)
{
    node *p;
    p = H;
    if (r < 1 || r >= H->elem)
    {
        printf("invalid position\n");
        return;
    }
    for (int i = 0;i < r;i++)
        p = p->next;
    printf("%c\n", p->data);
}
void PrintL(node * H)
{
    node *p = H->next;
    while (p != NULL) {
        printf("%c", p->data);
        p = p->next;
    }
}