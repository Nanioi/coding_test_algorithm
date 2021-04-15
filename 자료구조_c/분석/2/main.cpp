#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **a,int n){
    int i=0,j=0,row=0;
    while(i<n&&j<n)
    {
        if(a[i][j]==0)
            i++;
        else
        {
            row=i;
            j++;
        }
    }
    return row;
}
int main(){
    int n,i,j;
    int **a;

    scanf("%d",&n);
    a=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d",mostOnes(a,n));
}