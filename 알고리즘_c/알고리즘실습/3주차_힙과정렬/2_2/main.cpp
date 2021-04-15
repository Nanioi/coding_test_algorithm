//상향식 비재귀

#include<stdio.h>

void swap(int *a, int *b);
void downHeap(int H[], int num, int size);
void Print(int H[], int n);
void buildHeap(int H[], int n);

int main(void)
{
    int H[100] = { 0 }, n, i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &H[i]);
    }

    buildHeap(H, n);
    Print(H, n);
}
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void downHeap(int H[], int num, int size)
{
    int max;

    if (num * 2 > size && num * 2 + 1 > size){
        return;
    }
    max = num * 2;

    if (size >= num * 2 + 1){
        if(H[num*2+1]>H[max]){
            max = num * 2 + 1;
        }
    }
    if (H[num] > H[max]){
        return;
    }
    swap(&H[max], &H[num]);
    downHeap(H, max, size);
    return;
}
void Print(int H[], int n)
{
    int i = 1;

    while (i <= n)
    {
        printf(" %d", H[i++]);
    }
    printf("\n");
    return;
}
void buildHeap(int H[], int n)
{
    for(int i=n/2;i>=1;i-- ){
        downHeap(H,i,n);
    }
    return;
}