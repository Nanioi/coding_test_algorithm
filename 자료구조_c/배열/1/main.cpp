#include<stdio.h>
#include<stdlib.h>

void swap(int c, int x[] , int y[], int z[])
{
    int tmp = 0;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < (z[i] - y[i] + 1) / 2; j++)
        {

            tmp = x[z[i] - j];
            x[z[i] - j] = x[y[i] + j];
            x[y[i] + j] = tmp;
        }
    }
}
int main()
{
    int n,c;
    int x[100],*y,*z;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    scanf("%d", &c);
    y=(int *)malloc(sizeof(int)*c);
    z=(int *)malloc(sizeof(int)*c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &y[i]);
        scanf("%d", &z[i]);
    }
    swap(c, x, y, z);
    for (int i = 0; i < n; i++)
    {
        printf(" %d", x[i]);
    }
}