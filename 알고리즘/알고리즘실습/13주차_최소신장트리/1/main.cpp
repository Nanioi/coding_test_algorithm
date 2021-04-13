#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    int d;
    int flag;
}Node;
typedef struct array{
    int weight;
}Array;
int getMinVertex(Node *node,int n){
    int minVertex;
    int minWeight=INT_MAX;

    for(int i=1;i<=n;i++){
        if(node[i].flag==0&&node[i].d<minWeight){
            minVertex=i;
            minWeight=node[i].d;
        }
    }
    return minVertex;
}
void prim(Node *node,Array **array,int n){
    int cnt=1,sum=0;
    int minVertex=1;
    node[minVertex].flag=1;
    node[minVertex].d=0;
    for(int i=2;i<=n;i++){
        node[i].d=INT_MAX;
    }
    printf(" 1");

    while(cnt<n) {
        for (int i = 1; i <= n; i++) {
            if (node[i].flag == 0 && array[minVertex][i].weight != INT_MAX) {
                if (array[minVertex][i].weight < node[i].d)
                    node[i].d = array[minVertex][i].weight;
            }
        }
        minVertex = getMinVertex(node, n);
        if (node[minVertex].d == INT_MAX)
            return;
        node[minVertex].flag = 1;
        printf(" %d",minVertex);
        sum+=node[minVertex].d;
        cnt++;
    }
    printf("\n%d",sum);
}
int main(){
    int n,m,a,b,w;

    scanf("%d %d",&n,&m);
    Node *node=(Node *)malloc(sizeof(Node)*(n+1));
    for(int i=1;i<=n;i++){
        node[i].d = INT_MAX;
        node[i].flag = 0;
    }
    Array **array = (Array**)malloc(sizeof(Array*)*(n+1));
    for (int i = 1; i <= n; i++) {
        array[i] = (Array*)malloc(sizeof(Array)*(n+1));
        for (int j = 1; j <= n; j++) {
            array[i][j].weight = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);

        array[a][b].weight = w;
        array[b][a].weight = w;
    }
    prim(node, array, n);
}