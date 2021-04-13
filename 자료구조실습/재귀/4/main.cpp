#include <stdio.h>
#include <stdlib.h>

int max(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}
int max_a(int *a,int n){
    if(n==1)
        return a[0];
    else
        return max(a[n-1],max_a(a,n-1));
}

int main(){
    int n,*a;
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",max_a(a,n));
}