#include <stdio.h>
#include <stdlib.h>

int minCnt(int **x,int n,int m,int starti,int startj){
    if(n==starti||m==startj)// 시작점일때 1반환
        return 1;
    return minCnt(x,n-1,m,starti,startj)+minCnt(x,n,m-1,starti,startj);
    // 마지막점의 왼쪽까지 최단경로 수 + 마지막점 위쪽의 최단경로수
}
int main(){
    int n,m,**p,r,id,ni,mj;
    scanf("%d %d",&n,&m);
    scanf("%d",&id);// 학번입력받기
    id=id%100;//학번의 마지막 두자리 저장
    mj=id%10;//마지막 자리 저장
    ni=id/10;//학번마지막 두자리중 십의 자리 저장
    p=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        p[i]=(int *)malloc(sizeof(int )*m);
        for(int j=0;j<m;j++)
            p[i][j]=0;
    }//2차원 배열 동적할당해주기

    r=minCnt(p,ni,mj,0,0)*minCnt(p,n,m,ni,mj);
    // 학번(ni,mj)까지의 최단경로수 * 시작점이 (ni,mj)이고 마지막점이(n,m)인 최단경로수
    printf("%d",r);
}


