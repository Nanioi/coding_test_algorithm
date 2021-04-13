#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Node {
    struct Node *next;
    int data;
}node;

node *getnode();
node *addNode(node *p,int data);
int subset(node *x,node *y);
int member(node *p,int e);

int main(){
    int n,m,e;
    node *x,*y,*x1,*y1;
    x=getnode();
    y=getnode();
    x1=x;
    y1=y;

    scanf("%d",&n);
    if(n==0)
        x->next=NULL;
    else {
        for (int i = 0; i < n; i++) {
            getchar();
            scanf("%d", &e);
            x = addNode(x, e);
        }
    }
    getchar();
    scanf("%d",&m);
    if(m==0)
        y->next=NULL;
    else {
        for (int i = 0; i < m; i++) {
            getchar();
            scanf("%d", &e);
            y = addNode(y, e);
        }
    }
    printf("%d",subset(x1,y1));
}

node *getnode(){
    node *newNode;
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    return newNode;
}
node *addNode(node *p,int data){
    node *a;
    a=getnode();
    if(p->data==NULL){
        p->data=data;
        p->next=NULL;
    }
    else {
        a->data=data;
        a->next=NULL;
        p->next = a;
        p = a;
    }
    return p;
}
int member(node *p,int e){
    node *a;
    a=getnode();
    int c;

    if(p->data==NULL)
        return 0;
    a=p;
    while(1){
        c=a->data;
        if(c<e)
        {
            if(a->next==NULL)
                return 0;
            else
                a=a->next;

        } else if (c>e)
            return 0;

        else
            return 1;
    }
}


int subset(node *x,node *y)
{
    node *p;
    p=getnode();

    if(x->data==NULL)
        return 0;
    p=x;
    while(1){
        if(member(y,p->data)==1)
        {
            if(p->next==NULL)
                return 0;
            else
                p=p->next;
        } else
            return p->data;
    }
}
