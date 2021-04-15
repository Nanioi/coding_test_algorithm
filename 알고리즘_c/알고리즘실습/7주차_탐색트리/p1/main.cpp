#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int key;
    struct node  *parent;
    struct node  *rChild;
    struct node *lChild;
}node;
node *getnode(){
    node *a=(node *)malloc(sizeof(node));
    a->key=INT_MAX;
    a->lChild=NULL;
    a->parent=NULL;
    a->rChild=NULL;
    return a;
}
int isExternal(node *n){
    if(n->key==INT_MAX)
        return 1;
    else return 0;
}
void expandExternal(node *n) {
    n->rChild = getnode();
    n->lChild = getnode();
    n->rChild->parent = n;
    n->lChild->parent = n;
    return;
}
void insertItem(node **root,int key){
    node *a=*root;
    if(*root==NULL){
        *root=getnode();
        expandExternal(*root);
        return;
    }
    else {
        while (a->key != INT_MAX) {
            if (a->key > key)
                a = a->lChild;
            else if (a->key < key)
                a = a->rChild;
        }
    }
    a->key = key;
    expandExternal(a);
    return;
}
node *treeSearch(node *a, int key) {
    node *x = a;

    while (x->key != INT_MAX) {
        if (x->key == key)
            break;
        else if (x->key > key)
            x = x->lChild;
        else if (x->key < key)
            x = x->rChild;
    }
    return x;
}
void findElement(node *a, int key) {
    node *x = treeSearch(a, key);

    if (x->key == INT_MAX) {
        printf("X\n");
    }
    else {
        printf("%d\n", x->key);
    }
    return;
}
node *inOrderSucc(node *w){
    node *a=w->rChild;
    while(a->lChild->key!=INT_MAX){
        a=a->lChild;
    }
    return a;
}
node *sibling(node *a) {
    if (a->parent == NULL)
        return NULL;
    else if (a->parent->rChild == a)
        return a->parent->lChild;
    else
        return a->parent->rChild;
}
void reduceExternal(node *z,node **root){
    node *w=z->parent;
    node *zs,*g;
    zs=sibling(z);
    if(w->parent==NULL){
        *root=zs;
        zs->parent=NULL;
    }else{
        g=w->parent;
        zs->parent=g;
        if(w==g->lChild)
            g->lChild=zs;
        else
            g->rChild=zs;
    }
    free(z);
    free(w);
    return;
}
void deleteItem(node **root,int key){
    node *w=treeSearch(*root,key);

    if (w->key == INT_MAX) {
        printf("X\n");
        return;
    }

    printf("%d\n", w->key);
    node *z = w->lChild;

    if (!isExternal(z))
        z = w->rChild;
    if (isExternal(z))
        reduceExternal(z, root);
    else {
        node *y = inOrderSucc(w);
        node *z = y->lChild;
        w->key = y->key;
        reduceExternal(z, root);
    }
    return;
}
void printTree(node *a) {
    printf(" %d", a->key);

    if ((a->lChild)->key != INT_MAX)
        printTree(a->lChild);
    if ((a->rChild)->key != INT_MAX)
        printTree(a->rChild);

    return;
}
int main(){
    char  c;
    int  key;
    node *root = getnode();

    while (1) {
        scanf("%c", &c);
        if (c == 'i') {
            scanf("%d", &key);
            getchar();
            insertItem(&root, key);
        }
        if (c == 'd') {
            scanf("%d", &key);
            getchar();
            if (root != NULL) {
                deleteItem(&root, key);
            }
            else printf("X\n");
        }
        if (c == 's') {
            scanf("%d", &key);
            getchar();
            if (root != NULL) {
                findElement(root,key);
            }
        }
        if (c == 'p') {
            if (root->key != NULL) {
                printTree(root);
                printf("\n");
            }
        }
        if (c == 'q') {
            break;
        }
    }
    return 0;
}