#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Tnode {
    struct Tnode* L;
    struct Tnode* R;
    int data;
}Tnode;

Tnode* initTree();
int main() {
    Tnode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8,*p,*l,*r;
    int n;

    F1 = initTree();
    F2 = initTree();
    F3 = initTree();
    F4 = initTree();
    F5 = initTree();
    F6 = initTree();
    F7 = initTree();
    F8 = initTree();
    p = initTree();
    l = initTree();
    r = initTree();
    F1->data = 20;
    F1->L = F2;
    F1->R = F3;
    F2->data = 30;
    F2->L = F4;
    F2->R = F5;
    F3->data = 50;
    F3->R = F6;
    F4->data = 70;
    F5->data = 90;
    F6->data = 120;
    F6->L = F7;
    F6->R = F8;
    F7->data = 130;
    F8->data = 80;

    scanf("%d", &n);
    if (n == 1) {
        p = F1;
        l = F1->L;
        r = F1->R;
    }
    else if (n == 2) {
        p = F2;
        l = F2->L;
        r = F2->R;
    }
    else if (n == 3) {
        p = F3;
        l = F3->L;
        r = F3->R;
    }
    else if (n == 4) {
        p = F4;
        l = F4->L;
        r = F4->R;
    }
    else if (n == 5) {
        p = F5;
        l = F5->L;
        r = F5->R;
    }
    else if (n == 6) {
        p = F6;
        l = F6->L;
        r = F6->R;
    }
    else if (n == 7) {
        p = F7;
        l = F7->L;
        r = F7->R;
    }
    else if (n == 8) {
        p = F8;
        l = F8->L;
        r = F8->R;
    }
    else{
        p = NULL;
        l = NULL;
        r = NULL;
        printf("-1\n");
    }

    if (p != NULL)
        printf("%d ", p->data);
    if (l != NULL)
        printf("%d ", l->data);
    if (r != NULL)
        printf("%d", r->data);
}

Tnode* initTree()
{
    Tnode* T=(Tnode *)malloc(sizeof(Tnode));
    T->data=-1;
    T->L = NULL;
    T->R = NULL;
    return T;
}
