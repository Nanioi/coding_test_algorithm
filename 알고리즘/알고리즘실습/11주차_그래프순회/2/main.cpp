#include <stdio.h>
#include <stdlib.h>

int IsEmpty(int *front,int *rear);
void push(int *queue,int value,int *rear);
int pop(int *queue,int *front);
void bfs(int s,int *visit,int arr[][101],int n);

int main(){
    int arr[101][101];
    int visit[101];
    int n,m,s;
    int u,v;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=n;i++){
        visit[i]=0;
        for(int j=1;j<=n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        arr[u][v]=1;
        arr[v][u]=1;
    }
    bfs(s,visit,arr,n);
    return 0;
}
int IsEmpty(int *front,int *rear){
    if(*front == *rear)
        return 1;
    else
        return 0;
}
void push(int *queue,int value,int *rear){
    *rear=(*rear+1)%1000;
    queue[*rear]=value;
}
int pop(int *queue,int *front){
    *front=(*front+1)%1000;
    return queue[*front];
}
void bfs(int s,int *visit,int arr[][101],int n){
    int queue[1000];
    int front=-1,rear=-1;
    visit[s]=1;
    push(queue,s,&rear);
    while(!IsEmpty(&front,&rear)){
        int data=pop(queue,&front);
        printf("%d\n",data);
        for(int i=1;i<=n;i++){
            if(arr[data][i]==1&&visit[i]==0){
                visit[i]=1;
                push(queue,i,&rear);
            }
        }
    }
}