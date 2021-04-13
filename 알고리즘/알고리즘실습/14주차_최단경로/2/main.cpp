#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Bellman(int **ver,int *minWeight,int n,int s){
    minWeight[s]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            if(ver[i][j]!=0&&ver[i][j]!=INT_MAX){
                if(minWeight[j]>ver[i][j]+minWeight[i]) {
                    minWeight[j] = ver[i][j] + minWeight[i];
                }
            }
        }
    }
}
int main(){
    int **ver;
    int n,m,s;
    int start,end,weight;
    int *minWeight;
    scanf("%d %d %d",&n,&m,&s);
    ver=(int **)malloc(sizeof (int *)*(n+1));
    minWeight=(int *)malloc(sizeof (int )*(n+1));

    for(int i=1;i<=n;i++){
        ver[i]=(int *)malloc(sizeof (int)*(n+1));
        for(int j=1;j<=n;j++){
            if(i==j)
                ver[i][j]=0;
            else
                ver[i][j]=INT_MAX;
        }
        minWeight[i]=INT_MAX;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&start,&end,&weight);
        ver[start][end]=weight;
    }
    Bellman(ver,minWeight,n,s);
    for(int i=1;i<=n;i++){
        if(i==s || minWeight[i] == INT_MAX)
            continue;
        printf("%d %d\n",i,minWeight[i]);
    }
}