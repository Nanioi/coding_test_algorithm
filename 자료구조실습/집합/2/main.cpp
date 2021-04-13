#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct Node{
    struct Node *next;
    int data;
}Node;

typedef struct Set{
    Node* header;
    Node* tail;
}Set;

void addNode(Set *set, int num);
Set *Union(Set *x,Set *y);
Set *Intersect(Set *x,Set *y);


Node* getNode(){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

Set* initSet(Node *x){
    Set *newSet;

    newSet = (Set *)malloc(sizeof(Set));

    newSet->header = x;
    newSet->tail = x;
    return newSet;
}

int main(){

    int size, i, num;
    Node *x, *y,*U,*I;
    Set *setX, *setY,*resultU,*resultI;

    x = getNode();
    y = getNode();

    setX = initSet(x);
    setY = initSet(y);

    // x set
    scanf("%d", &size);


    if(size==0){
        x->next = NULL;
    } else {
        for (i = 0; i < size; i++) {
            scanf("%d", &num);
            addNode(setX, num);
        }
    }

    // y set

    scanf("%d", &size);

    if(size==0){
        y->next = NULL;
    } else {
        for(i = 0; i< size; i++){
            scanf("%d", &num);
            addNode(setY, num);
        }
    }

    U = getNode();
    I = getNode();

    resultU = initSet(U);
    resultI = initSet(I);

    resultU=Union(setX,setY);
    resultI=Intersect(setX,setY);

    U=resultU->header;
    while(U!=NULL){
        printf(" %d",U->data);
        U=U->next;
    }
    printf("\n");
    I=resultI->header;
    while(I!=NULL){
        printf(" %d",I->data);
        I=I->next;
    }
}

void addNode(Set *set, int num){
    Node *newNode = getNode();
    Node *p = set->tail;

    newNode->data = num;

    if(p->data == NULL){
        p->data = num;
    }
    else{
        p->next = newNode;
        set->tail = newNode;
    }
}
Set *Union(Set *x,Set *y){
    Node *a,*b,*z=getNode();
    Set *setZ;
    setZ = initSet(z);
    a=x->header;
    b=y->header;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data<b->data){
            addNode(setZ,a->data);
            a=a->next;
        } else if (a->data>b->data){
            addNode(setZ,b->data);
            b=b->next;
        }else{
            addNode(setZ,a->data);
            a=a->next;
            b=b->next;
        }
    }
    while(a!=NULL){
        addNode(setZ,a->data);
        a=a->next;
    }
    while(b!=NULL){
        addNode(setZ,b->data);
        b=b->next;
    }
    return setZ;
}
Set *Intersect(Set *x,Set *y){
    Node *a,*b,*z=getNode();
    Set *setZ;
    setZ = initSet(z);
    a=x->header;
    b=y->header;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data<b->data){
            a=a->next;
        } else if (a->data>b->data){
            b=b->next;
        }else{
            addNode(setZ,a->data);
            a=a->next;
            b=b->next;
        }
    }
    while(a!=NULL){
        a=a->next;
    }
    while(b!=NULL){
        b=b->next;
    }
    return setZ;
}