#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int *x,int n)
{
    int i,j,*a;
    double sum;
    a=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum+=x[j];
        }
        a[i]=(int)(sum/(i+1)+0.5);
    }
    return a;
}
int* prefixAverages2(int *x,int n)
{
    int i,*a;
    double sum=0.0;
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        sum+=x[i];
        a[i]=(int)(sum/(i+1)+0.5);
    }
    return a;
}
int main(){
    int n,*x,*r,i;

    scanf("%d",&n);
    x=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    r=prefixAverages1(x,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",r[i]);
    }
    printf("\n");
    r=prefixAverages2(x,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",r[i]);
    }
}