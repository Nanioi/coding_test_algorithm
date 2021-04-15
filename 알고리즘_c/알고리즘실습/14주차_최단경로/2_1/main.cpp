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
    struct node *adj;
}vertex;
node *getnode(){
    node *a=(node *)malloc(sizeof (node));
    a->next=NULL;
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
}
void Bellman(vertex *v,int s,int n){
    v[s].minWeight=0;
    for (int i = 1; i < n; i++) {
        node *a=v[i].adj;
        a=a->next;
        while(a!=NULL) {
            if(a->adjnum!=s && a->weight + v[i].minWeight < v[a->adjnum].minWeight)
                v[a->adjnum].minWeight=a->weight + v[i].minWeight;
            a=a->next;
        }
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
        v[i].minWeight=30000;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&start,&end,&weight);
        addVertex(v,start,end,weight);
    }
    Bellman(v,s,n);
    for(int i=1;i<=n;i++){
        if(i==s || v[i].minWeight==30000)
            continue;
        printf("%d %d\n",i,v[i].minWeight);
    }
}