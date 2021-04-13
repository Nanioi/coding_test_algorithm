#include <stdio.h>
#pragma warning(disable:4996)

void swap(int *x,int *y)
{
    int tmp;

    tmp=*x;
    *x=*y;
    *y=tmp;
}
int main()
{
    int n,a,b,x[50],*p;

    scanf("%d",&n);

    for(p=x;p<x+n;p++)
    {
        scanf("%d",p);
    }

    scanf("%d %d",&a,&b);

    swap(x+a,x+b);

    for(p=x;p<x+n;p++)
    {
        printf(" %d",*p);
    }
}

