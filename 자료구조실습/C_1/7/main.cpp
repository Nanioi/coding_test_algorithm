#include <stdio.h>
#include <stdlib.h>

void addArray(int *a,int *b,int *c,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        *(c+i)=*(a+i)+*(b+n-i-1);
    }
}
int main()
{
    int *x,*y,*z,*a,*b,*c;
    int n;

    scanf("%d",&n);
    x=(int *)malloc(sizeof(int)*n);
    y=(int *)malloc(sizeof(int)*n);
    z=(int *)malloc(sizeof(int)*n);

    for(a=x;a<x+n;a++)
    {
        scanf("%d",a);
    }
    for(b=y;b<y+n;b++)
    {
        scanf("%d",b);
    }
    addArray(x,y,z,n);

    for(c=z;c<z+n;c++)
    {
        printf(" %d",*c);
    }

}