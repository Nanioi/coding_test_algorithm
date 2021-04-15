#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int adjnum;
    int weight;
    struct node *next;
}node;
typedef struct vertex{
    int minWeight;
    int flag;
    struct node *adj;
}vertex;
node *getnode(){
    node *a=(node *)malloc(sizeof (node));
    a->next=NULL;
    a->weight=INT_MAX;
    return a;
}
void addVertex(vertex *v,int start,int end,int weight){
    node *a=v[start].adj;
    node *n=getnode();
    while(a->next!=NULL){
        a=a->next;
    }
    n->adjnum=end;
    n->weight=weight;
    a->next=n;

    node *b=v[end].adj;
    node *m=getnode();
    while(b->next!=NULL){
        b=b->next;
    }
    m->adjnum=start;
    m->weight=weight;
    b->next=m;
}
int getMinVertex(vertex *v,int n){
    int minVertex;
    int minWeight=INT_MAX;
    for(int i=1;i<=n;i++){
        if(v[i].flag==0&&v[i].minWeight<minWeight){
            minVertex=i;
            minWeight=v[i].minWeight;
        }
    }
    return minVertex;
}
void Dijkstra(vertex *v,int s,int n){
    int cnt=1;
    int minVertex=s;
    v[s].minWeight=0;
    v[s].flag=1;

    while(cnt<n){
        node *a=v[minVertex].adj;
        while(a->next!=NULL){
            if(v[a->next->adjnum].flag==0){
                if( a->next->weight+ v[minVertex].minWeight < v[a->next->adjnum].minWeight)
                    v[a->next->adjnum].minWeight=a->next->weight+ v[minVertex].minWeight;
            }
            a=a->next;
        }
        minVertex=getMinVertex(v,n);
        if(v[minVertex].minWeight==INT_MAX || v[minVertex].minWeight==30000)
            return;
        v[minVertex].flag=1;
        printf("%d %d\n",minVertex,v[minVertex].minWeight);
        cnt++;
    }
}
int main(){
    int n,m,s;
    vertex *v;
    int start,end,weight;

    scanf("%d %d %d",&n,&m,&s);
    v=(vertex *)malloc(sizeof (vertex)*(n+1));
    for(int i=1;i<=n;i++){
        v[i].adj=getnode();
        v[i].flag=0;
        v[i].minWeight=30000;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&start,&end,&weight);
        addVertex(v,start,end,weight);
    }
    Dijkstra(v,s,n);
}