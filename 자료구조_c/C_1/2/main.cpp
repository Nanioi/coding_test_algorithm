#include <stdio.h>
#pragma warning (disable:4996)

void ABC(int *x, int k)
{
    int *p,tmp, max;

    max = *(x+k);
    for (p = (x+k);p < (x + 10);p++)
    {
        if (max < *p)
        {
            max = *p;
        }
    }

    for (p = (x+k);p < (x + 10);p++)
    {
        if (max == *p)
        {
            tmp = *p;
            *p = *(x+k);
            *(x+k) = tmp;
        }
    }
}
int main()
{
    int x[10],*p,i;

    for (p = x;p < x + 10;p++)
    {
        scanf("%d", p);
    }
    p=x;
    for (i=0;i<10;i++)
    {
        ABC(p, i);
    }
    for (p = x;p < x + 10;p++)
    {
        printf(" %d", *p);
    }
}