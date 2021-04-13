#include <stdio.h>
#include <stdlib.h>

void addVer(int **arr,int u,int v,int w){
    arr[u][v]=w;
    arr[v][u]=w;
    return;
}
void printAdj(int **arr,int n){
    for(int i=1;i<=6;i++){
        if(arr[n][i]!=0)
            printf(" %d %d",i,arr[n][i]);
    }
    printf("\n");
    return;
}
void changeWeight(int **arr,int n,int m,int w){
    arr[n][m]=w;
    arr[m][n]=w;
}
int main(){
    int **arr,n,m,w;
    char c;

    arr=(int **)malloc(sizeof(int *)*7);
    for(int i=0;i<7;i++){
        arr[i]=(int *)malloc(sizeof(int)*7);
        for(int j=0;j<7;j++){
            arr[i][j]=0;
        }
    }
    addVer(arr,1,2,1);
    addVer(arr,1,3,1);
    addVer(arr,1,4,1);
    addVer(arr,1,6,2);
    addVer(arr,2,3,1);
    addVer(arr,3,5,4);
    addVer(arr,5,5,4);
    addVer(arr,5,6,3);

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
                printAdj(arr, n);
            }
        }
        if(c=='m'){
            scanf("%d %d %d",&n,&m,&w);
            getchar();
            if(n>6||n<1 ||m>6||m<1) {
                printf("-1\n");
            }else {
                changeWeight(arr, n, m, w);
            }
        }
    }
    return 0;

}