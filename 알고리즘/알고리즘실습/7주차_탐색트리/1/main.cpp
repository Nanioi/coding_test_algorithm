#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    int key;
    struct node *parent;
    struct node *rchild;
    struct node *lchild;
}Node;
Node *getnode(int data) {
    Node *a = (Node*)malloc(sizeof(Node));
    a->parent = NULL;
    a->lchild = NULL;
    a->rchild = NULL;
    a->key = data;
    return a;
}

Node *findElement(Node *root, int data);
int isExternal(Node *node);
int externalnode(Node *root);
void insertitem(Node *root, int data);
Node *deleteswapitem(Node *a);
void deleteItem(Node **root, int data);
void searchitem(Node *root, int data);
void printTree(Node *root);

int main() {
    char c;
    int data;
    Node *root = getnode(INT_MAX);
    while (1) {
        scanf("%c", &c);
        if (c == 'i') {
            scanf("%d", &data);
            getchar();
            insertitem(root, data);
        }
        if (c == 'd') {
            scanf("%d", &data);
            getchar();
            deleteItem(&root, data);
        }
        if (c == 's') {
            scanf("%d", &data);
            getchar();
            searchitem(root, data);
        }
        if (c == 'p') {
            if (root->key != INT_MAX) {
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
Node *findElement(Node *root, int data) {
    Node *a = root;
    while (1) {
        if (a->key > data && a->lchild != NULL)
            a = a->lchild;
        else if (a->key < data && a->rchild != NULL)
            a = a->rchild;
        else if (a->key == data)
            return a;
        else return NULL;
    }
}
int isExternal(Node *node) {
    if (node->lchild == NULL && node->rchild == NULL)
        return 1;
    else
        return 0;
}
int externalnode(Node *root) {
    if (root->key == INT_MAX && root->lchild == NULL && root->rchild == NULL) {
        return 1;
    }
    else
        return 0;
}
void insertitem(Node *root, int data) {
    Node *a, *x;
    a = root;
    if (externalnode(a) == 1) {
        a->key = data;
        return;
    }
    x = getnode(data);
    while (1) {
        if (a->key > data && a->lchild == NULL) {
            a->lchild = x;
            x->parent = a;
            return;
        }
        else if (a->key > data && a->lchild != NULL) {
            a = a->lchild;
        }
        if (a->key < data && a->rchild == NULL) {
            a->rchild = x;
            x->parent = a;
            return;
        }
        else if (a->key < data && a->rchild != NULL) {
            a = a->rchild;
        }
    }
}
Node *deleteswapitem(Node *a) {
    Node *x = a;
    x = x->rchild;
    while (x->lchild != NULL) {
        x = x->lchild;
    }
    return x;
}
void deleteItem(Node **root, int data) {
    Node *a = *root, *b;
    Node *q = findElement(a, data);
    if (q == NULL) {
        printf("X\n");
        return;
    }
    if (q == a) {
        printf("%d\n", q->key);
        if (isExternal(q) == 1)
            q->key = INT_MAX;
        else if (q->lchild == NULL &&q->rchild != NULL) {
            *root = (q->rchild);
        }
        else if (q->lchild != NULL &&q->rchild == NULL) {
            *root = (q->lchild);
        }
        else {
            b = deleteswapitem(q);
            q->key = b->key;
            if (b->rchild != NULL && q->rchild != b) {
                b->parent->lchild = b->rchild;
                b->rchild->parent = b->parent;
            }
            else if (b->rchild != NULL && q->rchild == b) {
                q->rchild = b->rchild;
                b->rchild->parent = q;
            }
            else {
                if (b->parent->rchild == b) {
                    b->parent->rchild = NULL;
                }
                else if (b->parent->lchild == b) {
                    b->parent->lchild = NULL;
                }
            }
        }
    }
    else {
        printf("%d\n", q->key);
        if (isExternal(q) == 1) {
            if (q->parent->rchild == q) q->parent->rchild = NULL;
            else if (q->parent->lchild == q) q->parent->lchild = NULL;
            free(q);
        }
        else if (q->lchild == NULL &&q->rchild != NULL) {
            if (q->parent->rchild == q) {
                q->parent->rchild = q->rchild;
                q->rchild->parent = q->parent;
            }
            else if (q->parent->lchild == q) {
                q->parent->lchild = q->rchild;
                q->rchild->parent = q->parent;
            }
        }
        else if (q->lchild != NULL &&q->rchild == NULL) {
            if (q->parent->rchild == q) {
                q->parent->rchild = q->lchild;
                q->lchild->parent = q->parent;
            }
            else if (q->parent->lchild == q) {
                q->parent->lchild = q->lchild;
                q->lchild->parent = q->parent;
            }
        }
        else {
            b = deleteswapitem(q);
            q->key = b->key;
            if (b->rchild != NULL && q->rchild != b) {
                b->parent->lchild = b->rchild;
                b->rchild->parent = b->parent;
            }
            else if (b->rchild != NULL && q->rchild == b) {
                q->rchild = b->rchild;
                b->rchild->parent = q;
            }
            else {
                if (b->parent->rchild == b) {
                    b->parent->rchild = NULL;
                }
                else if (b->parent->lchild == b) {
                    b->parent->lchild = NULL;
                }
            }
        }
    }
    return;
}
void searchitem(Node *root, int data) {
    Node *a = findElement(root, data);
    if (a == NULL)
        printf("X\n");
    else
        printf("%d\n", a->key);
    return;
}
void printTree(Node *root) {
    printf(" %d", root->key);
    if (root->lchild != NULL)
        printTree(root->lchild);
    if (root->rchild != NULL)
        printTree(root->rchild);
    return;
}