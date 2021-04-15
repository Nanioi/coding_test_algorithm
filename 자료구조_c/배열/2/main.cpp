#include<stdio.h>
#include<stdlib.h>

void swap(int c, int x[] , int y[])
{
    int tmp = 0,*p,*q;
    for(q=y+1;q<y+(c-1);q++){
        tmp=x[y[0]];
        x[y[0]]=x[*q];
        x[*q]=tmp;
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
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &y[i]);
    }
    swap(c, x, y);
    for (int i = 0; i < n; i++)
    {
        printf(" %d", x[i]);
    }
}