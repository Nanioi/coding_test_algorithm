#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Tnode {
    struct Tnode* L;
    struct Tnode* R;
    int id;
    int data;
}Tnode;

Tnode* initTree();
void preOrder(Tnode* T);
void postOrder(Tnode* T);
void inOrder(Tnode* T);
int isInternal(Tnode* T);
void visit(Tnode* T);

void main() {
    Tnode *F[9],*T=initTree();
    int n,m;

    for (int i = 0; i < 9; i++) {
        F[i] = initTree();
        F[i]->id = i + 1;
    }
    F[0]->data = 20;
    F[0]->L = F[1];
    F[0]->R = F[2];
    F[1]->data = 30;
    F[1]->L = F[3];
    F[1]->R = F[4];
    F[2]->data = 50;
    F[2]->R = F[5];
    F[3]->data = 70;
    F[4]->data = 90;
    F[5]->data = 120;
    F[5]->L = F[6];
    F[5]->R = F[7];
    F[6]->data = 130;
    F[7]->data = 80;

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < 9; i++) {
        if (F[i]->id == m)
        {
            T = F[i];
            break;
        }
    }
    if (m > 8)
    {
        printf("-1");
        return;
    }
    if (n == 1) {
        preOrder(T);
    }
    else if (n == 2)
        inOrder(T);
    else
        postOrder(T);
}

Tnode* initTree()
{
    Tnode* T = (Tnode*)malloc(sizeof(Tnode));
    T->data = -1;
    T->L = NULL;
    T->R = NULL;
    return T;
}

void preOrder(Tnode* T)
{
    if (T == NULL)
        return;
    visit(T);
    preOrder(T->L);
    preOrder(T->R);
}

void postOrder(Tnode* T)
{

    if (T == NULL)
        return;
    postOrder(T->L);
    postOrder(T->R);
    visit(T);
}

void inOrder(Tnode* T)
{

    if (T == NULL)
        return;
    inOrder(T->L);
    visit(T);
    inOrder(T->R);
}

int isInternal(Tnode* T)
{
    if (T->L != NULL && T->R != NULL)
        return 1;
    return 0;
}

void visit(Tnode* T)
{
    printf(" %d", T->data);
}
