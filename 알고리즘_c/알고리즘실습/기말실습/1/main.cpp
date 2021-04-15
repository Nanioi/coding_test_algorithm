#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int num;
    int flag;
    int d;
}node;
typedef struct array{
    int weight;

}array;
int getMinVertex(node *node,int n){
    int minVertex;
    int minWeight=INT_MAX;
    for(int i=1;i<=n;i++){
        if(node[i].flag==0&&node[i].d<minWeight)
        {
            minVertex=node[i].num;
            minWeight=node[i].d;
        }
    }
    return minVertex;
}
void prim(node *node,array **arr,int n){
    int cnt=1,sum=0;
    int minVertex=node[0].num,prev=1;
    node[minVertex].d=0;
    node[minVertex].flag=1;
    for(int i=2;i<=n;i++){
        node[i].d=INT_MAX;
    }
    while(cnt<n){
        for(int i=1;i<=n;i++){
            if(node[i].flag==0&&arr[minVertex][i].weight!=INT_MAX){
                if(arr[minVertex][i].weight<node[i].d)
                    node[i].d=arr[minVertex][i].weight;
            }
        }
        prev=minVertex;
        minVertex=getMinVertex(node,n);
        if(node[minVertex].d==INT_MAX)
            return;
        node[minVertex].flag=1;
        printf("%d %d %d\n",prev,minVertex,node[minVertex].d);
        sum+=node[minVertex].d;
        cnt++;
    }
}
int main(){
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    node* Node;
    Node=(node *)malloc(sizeof(node)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&Node[i].num);
        Node[i].d=INT_MAX;
        Node[i].flag=0;
    }
    array **arr=(array **)malloc(sizeof(array *)*n);
    for(int i=0;i<n;i++){
        arr[i]=(array *)malloc(sizeof(arr)*n);
        for(int j=0;j<n;j++){
            arr[i][j].weight=INT_MAX;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        arr[u][v].weight=w;
        arr[v][u].weight=w;
    }
    prim(Node,arr,n);
}