#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Tnode {
    struct Tnode* L;
    struct Tnode* R;
    int id;
}Tnode;

Tnode* initTree();
void newTNode(Tnode* T);
void search(Tnode* T);

int main() {
    int n, cnt,m,l,r;
    Tnode *T,*root,*left,*right;

    scanf("%d", &n);

    scanf("%d %d %d", &m, &l, &r);

    root = initTree();
    left = initTree();
    right = initTree();

    root->id = m;
    T = root;

    left->id = l;
    root->L = left;
    if (l != 0) {
        newTNode(T->L);
    }
    right->id = r;
    root->R = right;
    if (r != 0) {
        newTNode(T->R);
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        search(T);
    }
}

Tnode* initTree()
{
    Tnode* T = (Tnode*)malloc(sizeof(Tnode));
    T->L = NULL;
    T->R = NULL;
    return T;
}

void newTNode(Tnode* T)
{
    int pn, ln, rn;
    Tnode* TL, * TR;
    TL = initTree();
    TR = initTree();
    scanf("%d %d %d", &pn, &ln, &rn);

    TL->id = ln;
    T->L = TL;
    TR->id = rn;
    T->R = TR;
    if (ln != 0) {
        newTNode(T->L);
    }
    if (rn != 0) {
        newTNode(T->R);
    }
}

void search(Tnode* T)
{
    Tnode* tmp = T;
    int length;
    char A[100];
    scanf("%s", A);
    getchar();
    length = strlen(A);

    printf(" %d", tmp->id);

    for (int i = 0; i < length; i++) {
        if (A[i] == 'L')
        {
            tmp = tmp->L;
            printf(" %d", tmp->id);
        }
        if (A[i] == 'R')
        {
            tmp = tmp->R;
            printf(" %d", tmp->id);
        }
    }
    printf("\n");
}
