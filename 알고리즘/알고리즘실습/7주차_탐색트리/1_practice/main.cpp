#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    struct node *parent;
    struct node *right;
    struct node *left;
    int key;
}Node;

Node *getnode(int data) {
    Node *a = (Node*)malloc(sizeof(Node));
    a->parent = NULL;
    a->right = NULL;
    a->left = NULL;
    a->key = data;
    return a;
}
Node *inOrderSucc(Node *a) {
    Node *x = a;
    while (x->key != INT_MAX) {
        x = x->left;
    }
    return x;
}
Node *sibling(Node *a) {
    if (a->parent == NULL)
        return NULL;
    else if (a->parent->right == a)
        return a->parent->left;
    else
        return a->parent->right;
}
void reduceExternal(Node *a, Node **root) {
    Node *w, *g, *zs;

    w=a->parent;
    g=w->parent;
    zs=sibling(a);

    if (w->parent == NULL) {
        *root = zs;
        zs->parent = NULL;
    }
    else {
        zs->parent = g;

        if (g->left == w)
            g->left = zs;
        else
            g->right = zs;
    }
    free(a);
    free(w);
}
int isExternal(Node *a) {
    if (a->key == INT_MAX) {
        return 1;
    }
    else
        return 0;
}
void expandExternal(Node *node) {
    node->right = getnode(INT_MAX);
    node->left = getnode(INT_MAX);
    node->right->parent = node;
    node->left->parent = node;
    return;
}
void insertitem(Node **root, int key) {
    Node *a = *root;

    if (*root == NULL) {
        *root = getnode(key);
        expandExternal(*root);
        return;
    }
    else {
        while (a->key != INT_MAX) {
            if (a->key > key)
                a = a->left;
            else if (a->key < key)
                a = a->right;
        }
    }
    a->key = key;
    expandExternal(a);
    return;
}
void printT(Node *a) {
    printf(" %d", a->key);

    if ((a->left)->key != INT_MAX)
        printT(a->left);
    if ((a->right)->key != INT_MAX)
        printT(a->right);

    return;
}
Node *treeSearch(Node *a, int key) {
    Node *x = a;

    while (x->key != INT_MAX) {
        if (x->key == key)
            break;
        else if (x->key > key)
            x = x->left;
        else if (x->key < key)
            x = x->right;
    }
    return x;
}
void findElement(Node *a, int key) {
    Node *x = treeSearch(a, key);

    if (x->key == INT_MAX) {
        printf("X\n");
    }
    else {
        printf("%d\n", x->key);
    }

    return;
}
void removeExternal(Node **a, int key) {
    Node *w, *zs;
    w=treeSearch(*a,key);

    if (w->key == INT_MAX) {
        printf("X\n");
        return;
    }

    printf("%d\n", w->key);
    Node *z = w->left;

    if (isExternal(z) == 0)
        z = w->right;
    if (isExternal(z) == 1)
        reduceExternal(z, a);
    else {
        z = inOrderSucc(z);
        Node *y = z->parent;
        w->key = y->key;
        reduceExternal(z, a);
    }
    return;
}
int main() {
    char c;
    int key;

    Node *root = NULL;
    while (1) {
        scanf("%c", &c);
        if (c == 'i') {
            scanf("%d", &key);
            getchar();
            insertitem(&root, key);
        }
        if (c == 'd') {
            scanf("%d", &key);
            getchar();
            if (root != NULL) {
                removeExternal(&root, key);
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
            if (root != NULL) {
                printT(root);
                printf("\n");
            }
        }
        if (c == 'q') {
            break;
        }
    }
    return 0;
}