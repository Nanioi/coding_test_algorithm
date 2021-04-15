#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    struct node *parent;
    struct node *right;
    struct node *left;
    int height;
    int key;
}Node;

Node *getnode(int data, int height) {
    Node *a = (Node*)malloc(sizeof(Node));
    a->parent = NULL;
    a->right = NULL;
    a->left = NULL;
    a->key = data;
    a->height = height;
    return a;
}

Node *inOrderSucc(Node *a);
Node *sibling(Node *a);
Node *reduceExternal(Node *a, Node **root);
int isExternal(Node *a);
void expandExternal(Node *a);
int isBalanced(Node *a);
int updateHeight(Node *a);
Node *restructure(Node *x, Node *y, Node *z, Node **root);
void searchAndFixAfterInsertion(Node *a, Node **root);
void searchAndFixAfterRemove(Node *a, Node **root);
void insertitem(Node **root, int key);
void printT(Node *a);
Node *treeSearch(Node *a, int key);
void findElement(Node *a, int key);

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
Node *reduceExternal(Node *a, Node **root) {
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

    return zs;
}
int isExternal(Node *a) {
    if (a->key == INT_MAX) {
        return 1;
    }
    else
        return 0;
}
void expandExternal(Node *node) {
    node->right = getnode(INT_MAX, 0);
    node->left = getnode(INT_MAX, 0);
    node->right->parent = node;
    node->left->parent = node;
    node->height = 1;
    return;
}
int isBalanced(Node *a) {
    if ((a->right)->height - (a->left)->height >= 2 || (a->right)->height - (a->left)->height <= -2)
        return 0;
    else
        return 1;
}
int updateHeight(Node *a) {
    int maxHeight;
    maxHeight=(a->left)->height;

    if (maxHeight < (a->right)->height)
        maxHeight = (a->right)->height;

    if (maxHeight + 1 != a->height) {
        a->height = maxHeight + 1;
        return 1;
    }
    else return 0;
}
Node *restructure(Node *x, Node *y, Node *z, Node **root) {
    Node *t0, *t1, *t2, *t3, *a, *b, *c;

    if (z->key < y->key) {
        t0 = z->left;
        a = z;
        if (y->key < x->key) {
            t1 = y->left;
            t2 = x->left;
            t3 = x->right;
            b = y;
            c = x;
        }
        else {
            t1 = x->left;
            t2 = x->right;
            t3 = y->right;
            b = x;
            c = y;
        }
    }
    else {
        t3 = z->right;
        c = z;
        if (y->key > x->key) {
            t2 = y->right;
            t1 = x->right;
            t0 = x->left;
            b = y;
            a = x;
        }
        else {
            t2 = x->right;
            t1 = x->left;
            t0 = y->left;
            b = x;
            a = y;
        }
    }
    if (z->parent == NULL) {
        (*root) = b;
        (*root)->parent = NULL;
    }
    else if (z->parent->right == z) {
        z->parent->right = b;
        b->parent = z->parent;
    }
    else {
        z->parent->left = b;
        b->parent = z->parent;
    }

    b->left = a;
    b->right = c;
    a->parent = b;
    c->parent = b;
    a->left = t0;
    a->right = t1;
    c->left = t2;
    c->right = t3;

    t0->parent = a;
    t1->parent = a;
    t2->parent = c;
    t3->parent = c;

    updateHeight(a);
    updateHeight(c);
    updateHeight(b);

    return b;
}
void searchAndFixAfterInsertion(Node *a, Node **root) {
    Node *z = a->parent, *y, *x;

    if (a->parent == NULL)
        return;
    while (updateHeight(z) && isBalanced(z)) {
        if (z->parent == NULL)
            return;
        z = z->parent;
    }
    if (isBalanced(z))
        return;
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;
    if (y->left->height > y->right->height)
        x = y->left;
    else
        x = y->right;

    restructure(x, y, z, root);

    return;
}
void searchAndFixAfterRemove(Node *a, Node **root) {

    Node *z = a->parent, *y, *x, *b;

    if (a->parent == NULL)
        return;
    while (updateHeight(z) && isBalanced(z)) {
        if (z->parent == NULL) return;
        z = z->parent;
    }
    if (isBalanced(z))
        return;
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;
    if (y->left->height > y->right->height)
        x = y->left;
    else if (y->left->height < y->right->height)
        x = y->right;
    else {
        if (z->left == y) x = y->left;
        else x = y->right;
    }

    b = restructure(x, y, z, root);
    if (b->parent == NULL)
        return;

    searchAndFixAfterRemove(b, root);
    return;
}
void insertitem(Node **root, int key) {
    Node *a = *root;

    if (*root == NULL) {
        *root = getnode(key, 1);
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
    a->height = 1;
    expandExternal(a);
    searchAndFixAfterInsertion(a, root);
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