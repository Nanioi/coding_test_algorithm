#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int coef,exp;
}node;
node *getnode();
node *appenTerm(node *k,int c,int e);
node *addPoly(node *x,node *y);
int main(){
    int n1,n2,c,e;
    node *x,*y,*r,*xh,*yh;
    x=getnode();
    xh=x;
    y=getnode();
    yh=y;

    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        getchar();
        scanf("%d %d",&c,&e);
        x=appenTerm(x,c,e);
    }
    getchar();
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        getchar();
        scanf("%d %d",&c,&e);
        y=appenTerm(y,c,e);
    }
    r=addPoly(xh,yh);
    r=r->next;

    while(r!=NULL)
    {
        printf(" %d %d",r->coef,r->exp);
        r=r->next;
    }
}
node *getnode()
{
    node *h;
    h = (node *)malloc(sizeof(node));
    h->next = NULL;

    return h;
}
node *appenTerm(node *k,int c,int e)
{
    node *t;
    t=getnode();
    t->coef=c;
    t->exp=e;
    t->next=NULL;
    k->next=t;
    k=t;
    return k;
}
node *addPoly(node *x,node *y){
    node *result,*i,*j,*k;
    int sum=0;
    result=getnode();
    result->next=NULL;
    i=x->next;
    j=y->next;
    k=result;
    while((i!=NULL)&&(j!=NULL)){
        if((i->exp)>(j->exp))
        {
            k=appenTerm(k,i->coef,i->exp);
            i=i->next;
        }
        else if((i->exp)<(j->exp)){
            k=appenTerm(k,j->coef,j->exp);
            j=j->next;
        } else{
            sum=(i->coef)+(j->coef);
            if(sum!=0)
                k=appenTerm(k,sum,i->exp);
            i=i->next;
            j=j->next;
        }
    }
    while(i!=NULL){
        k=appenTerm(k,i->coef,i->exp);
        i=i->next;
    }
    while(j!=NULL){
        k=appenTerm(k,j->coef,j->exp);
        j=j->next;
    }
    return result;
}