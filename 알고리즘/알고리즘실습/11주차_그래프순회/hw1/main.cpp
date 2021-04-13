//DFS 비재귀버전(스택사용)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    int val;
}node;
typedef struct adjList{
    struct Node *head;
}adj;
typedef struct Stack {
    int A[101];
    int top;
}stack;
void initStack(stack *S);
void push(stack* S, int key);
void pop(stack* S);
void addNode(adj *arr,int v);
void dfs(int s,int *visit,adj *arr);
void freeAll(adj *arr);

int main(){
    adj arr[101];
    int visit[101];
    int n,m,s;
    int u,v;

    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=n;i++){
        arr[i].head=(node *)malloc(sizeof(node));
        arr[i].head->next=NULL;
        visit[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        addNode(arr+u,v);
        addNode(arr+v,u);
    }
    dfs(s,visit,arr);
    for(int i=1;i<=n;i++){
        freeAll(arr+i);
    }
    return 0;
}
void initStack(stack *S){
    S->top=-1;
}
void addNode(adj *arr,int v){
    node *head=arr->head;
    node *newNode=(node *)malloc(sizeof(node));

    newNode->val=v;
    while(head->next != NULL){
        if(head->next->val>v)
            break;
        head=head->next;
    }
    newNode->next=head->next;
    head->next=newNode;
}
void dfs(int s,int *visit,adj *arr) {
    stack S;
    initStack(&S);
    push(&S, s);
    visit[s]=1;
    printf("%d\n",s);

    while ((S.top)>-1) {
        int flag=0,p;
        int current = S.A[S.top];
        node *head = arr[current].head;
        while (head->next!= NULL) {
            if (visit[head->next->val]==0) {
                flag=1;
                visit[head->next->val]=1;
                push(&S, head->next->val);
                printf("%d\n",head->next->val);
                break;
            }
            head = head->next;
        }
        if(flag==0){
            pop(&S);
        }
    }
}
void freeAll(adj *arr){
    node *head=arr->head;
    node *next=arr->head->next;
    while(next!=NULL){
        free(head);
        head=next;
        next=next->next;
    }
    free(head);
}
void push(stack* S, int key) {
    S->A[++(S->top)] = key;
    return;
}
void pop(stack* S) {
    if(S->top==-1)
        return;
    else
        (S->top)--;
    return;
}