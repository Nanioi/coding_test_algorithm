#include <stdio.h>
#include <stdlib.h>

int minCnt(int **x,int n,int m){
    if(n==0||m==0)
        return 1;// 첫번쩨 시작점에서 1반환
    return minCnt(x,n-1,m)+minCnt(x,n,m-1);
    //마지막 지점의 왼쪽 까지 올 경로의 최단경로 수 + 마지막 지점의 위쪽 까지 올 경로 최단경로 수
}
int main(){
    int n,m,**p,r;
    scanf("%d %d",&n,&m);
    p=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        p[i]=(int *)malloc(sizeof(int )*m);//p에 2차원 배열 할당해주기
        for(int j=0;j<m;j++)
            p[i][j]=0;//0으로 초기화
    }
    r=minCnt(p,n,m);// 재귀함수를 불러들여 nxm의 2차원배열의 최단경로의 수를 r에 저장
    printf("%d",r);
}


