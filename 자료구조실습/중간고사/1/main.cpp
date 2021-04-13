#include <stdio.h>
#include <stdlib.h>

int MaxSub(int *A,int n){
    int r,max=0;//ASS 1
    for(int i=0;i<n-1;i++){//ASS,EXP n번
        for(int j=i+1;j<n;j++)//ASS,EXP n-i번
        {
            r=*(A+i)-*(A+j);//ASS 1,EXP 1,IND 2
            if(r<0)//EXP 1
                r*=-1;//ASS 1,EXP 1
            if(max<r)//EXP 1
                max=r;//ASS 1
        }
    }
    return max;//차이의 최댓값 반환,RET 1
    // 이 함수의 실행 속도는 O(n^2)
}
int count(int *A,int n){
    int cnt=0;//ASS 1
    int *p;
    for(p=A;p<A+n;p++){//ASS,EXP,IND
        if(*p<0)//음수이면 cnt값 증가,IND, EXP
            cnt++;//EXP 1
    }
    return cnt;// 결과값 반환, RET 1
    // 실행속도는 O(n)
}
