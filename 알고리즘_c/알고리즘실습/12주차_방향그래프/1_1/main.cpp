#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int elem;
}node;
typedef struct Vertex {
    node *outedges;
    node *inedges;
    char name;
    int indegree;
}vertex;
typedef struct edge {
    int origin;
    int destination;
}edge;
typedef struct Graph {
    vertex *vertices;
    edge *edges;
}Graph;
typedef struct Queue {
    int front;
    int rear;
    int *queue;
}Queue;

void insertVertex(Graph *G,char vName,int i);
node *getnode();
void insertDirectedEdge(Graph *G,int u,int w,int i);
int index(Graph G,char vName,int n);
void insertFirst(node *H,int i);
int *topologicalSort(Graph *G,int *topOrder,int n);
int isEmpty(Queue Q);
void Enqueue(Queue *Q,int i,int n);
int Dequeue(Queue *Q,int n);
void freeAll(Graph *G,int n);

int main(){
    int *topOrder;
    Graph G;
    char vName,uName,wName;
    int n,m,u,w;

    scanf("%d",&n);
    getchar();
    G.vertices=(vertex *)malloc(sizeof(vertex)*n);
    for(int i=0;i<n;i++){
        scanf("%c",&vName);
        getchar();
        insertVertex(&G,vName,i);
    }
    scanf("%d",&m);
    getchar();
    G.edges=(edge *)malloc(sizeof(edge)*m);
    for(int i=0;i<m;i++){
        scanf("%c %c",&uName,&wName);
        getchar();
        u=index(G,uName,n);
        w=index(G,wName,n);
        insertDirectedEdge(&G,u,w,i);
    }
    topOrder=(int *)malloc(sizeof(int)*(n+1));
    topOrder=topologicalSort(&G,topOrder,n);
    if(topOrder[0]==0){
        printf("0\n");
    }else{
        for(int i=1;i<=n;i++){
            printf("%c ",G.vertices[topOrder[i]].name);
        }
    }
    freeAll(&G,n);
    return 0;
}
void insertVertex(Graph *G,char vName,int i){
    G->vertices[i].name=vName;
    G->vertices[i].outedges=getnode();
    G->vertices[i].inedges=getnode();
    G->vertices[i].indegree=0;
    return;
}
node *getnode(){
    node *n=(node *)malloc(sizeof(node));
    n->next=NULL;
    return n;
}
void insertDirectedEdge(Graph *G,int u,int w,int i){
    G->edges[i].origin=u;
    G->edges[i].destination=w;
    insertFirst(G->vertices[u].outedges,i);
    insertFirst(G->vertices[w].inedges,i);
    G->vertices[w].indegree++;
}
int index(Graph G,char vName,int n){
    for(int i=0;i<n;i++){
        if(G.vertices[i].name==vName){
            return i;
        }
    }
}
void insertFirst(node *H,int i){
    node *n = getnode();
    n->elem = i;
    n->next = H->next;
    H->next=n;
    return;
}
int *topologicalSort(Graph *G,int *topOrder,int n){
    int *in=(int *)malloc(sizeof(int)*n);
    Queue *Q;
    Q=(Queue *)malloc(sizeof(Queue));
    Q->queue=(int *)malloc(sizeof(int)*n);
    Q->front=-1;
    Q->rear=-1;

    for(int i=0;i<n;i++){
        in[i]=G->vertices[i].indegree;
        if(in[i]==0)
            Enqueue(Q,i,n);
    }
    int v,u,w;
    int t=1;
    node *cur;
    while(!isEmpty(*Q)){
        v=Dequeue(Q,n);
        topOrder[t]=v;
        t++;
        cur = G->vertices[v].outedges->next;
        while(cur!=NULL){
            u=cur->elem;
            w=G->edges[u].destination;
            in[w]--;
            if(in[w]==0)
                Enqueue(Q,w,n);
            cur=cur->next;
        }
    }
    if(t<=n) topOrder[0]=0;
    else topOrder[0]=1;
    free(in);
    return topOrder;
}
int isEmpty(Queue Q){
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}
void Enqueue(Queue *Q,int i,int n){
    Q->rear=(Q->rear+1)%n;
    Q->queue[Q->rear]=i;
    return;
}
int Dequeue(Queue *Q,int n){
    Q->front=(Q->front+1)%n;
    return Q->queue[Q->front];
}
void freeAll(Graph *G,int n){
    node *h1,*next1,*h2,*next2;
    for(int i=0;i<n;i++){
        next1=G->vertices[i].outedges->next;
        h1=G->vertices[i].outedges;
        next2=G->vertices[i].inedges->next;
        h2=G->vertices[i].inedges;
        while(next1!=NULL){
            free(h1);
            h1=next1;
            next1=next1->next;
        }
        while(next2!=NULL){
            free(h2);
            h2=next2;
            next2=next2->next;
        }
        free(h1);
        free(h2);
    }
}