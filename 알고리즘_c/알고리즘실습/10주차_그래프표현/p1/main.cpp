#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int adjnum;
    int weight;
    struct node *next;
}node;
typedef struct Vertex{
    struct node *header;
}vertex;
typedef struct Edge{
    int start;
    int end;
    int weight;
    struct Edge *next;
}edge;
node *getnode(){
    node *a=(node *)malloc(sizeof (node));
    a->adjnum=INT_MAX;
    a->weight=0;
    a->next=NULL;
    return a;
}
edge *getEdges() {
    edge *a = (edge*)malloc(sizeof(edge));
    a->start=0;
    a->end=0;
    a->weight=0;
    a->next = NULL;
    return a;
}
void addEdge(edge *e,int start,int end,int weight) {
    edge *a =e,*n;
    n=getEdges();
    while (a->next != NULL) {
        a=a->next;
    }
    n->start = start;
    n->end = end;
    n->weight = weight;
    a->next=n;
}
void addVertex(vertex *v,int adjnum,int weight){
    node *h=v->header;
    node *n=getnode();
    n->weight=weight;
    n->adjnum=adjnum;
    while(h->next!=NULL){
        if(h->next->adjnum > n->adjnum)
            break;
        h=h->next;
    }
    n->next=h->next;
    h->next=n;
}
void printAdj(vertex *v,int n){
    node *a=v[n].header;
    while(a->next!=NULL){
        printf(" %d %d",a->next->adjnum,a->next->weight);
        a=a->next;
    }
    printf("\n");
    return;
}
void changeWeight(vertex *v,edge *e,int n,int m,int w){
    node *a=v[n].header;
    node *b=v[m].header;
    int flag=0;
    while(a->next!=NULL){
        if(a->next->adjnum==m){
            flag=1;
            a->next->weight=w;
            if(w==0){
                a->next=a->next->next;
            }
            break;
        }
        a=a->next;
    }
    while(b->next!=NULL){
        if(b->next->adjnum==n){
            flag=1;
            b->next->weight=w;
            if(w==0){
                b->next=b->next->next;
            }
            break;
        }
        b=b->next;
    }
    if(flag==0){
        addEdge(e,n,m,w);
        if(n==m){
            addVertex(v+n,m,w);
        }else {
            addVertex(v + n, m, w);
            addVertex(v + m, n, w);
        }
    }
    return;
}
int main(){
    vertex v[7];
    char c;
    int n,m,w;
    edge *e=getEdges();
    for(int i=1;i<=6;i++){
        v[i].header=getnode();
    }

    addEdge(e,1,2,1);
    addEdge(e,1,3,1);
    addEdge(e,1,4,1);
    addEdge(e,1,6,2);
    addEdge(e,2,3,1);
    addEdge(e,3,5,4);
    addEdge(e,5,5,4);
    addEdge(e,5,6,3);

    edge *a=e->next;
    while(a!=NULL){
        if(a->start==a->end){
            addVertex(v+(a->start),a->end,a->weight);
        }else {
            addVertex(v + (a->start), a->end, a->weight);
            addVertex(v + (a->end), a->start, a->weight);
        }
        a=a->next;
    }
    while(1){
        scanf("%c",&c);
        if(c=='q')
            break;
        if(c=='a'){
            scanf("%d",&n);
            getchar();
            if(n>6||n<1){
                printf("-1\n");
            }else {
                printAdj(v, n);
            }
        }
        if(c=='m'){
            scanf("%d %d %d",&n,&m,&w);
            getchar();
            if(n>6||n<1 ||m>6||m<1) {
                printf("-1\n");
            }else {
                changeWeight(v, e, n, m, w);
            }
        }
    }
    return 0;
}