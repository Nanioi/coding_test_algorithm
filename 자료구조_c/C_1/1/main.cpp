#include <stdio.h>

int sum(int n)
{
    if(n==1)
        return 1;
    return n+sum(n-1);
}
int main()
{
    int x,i,r=0;

    scanf("%d",&x);

    for(i=1;i<=x;i++)
    {
        r+=sum(i);
    }
    printf("%d",r);

}