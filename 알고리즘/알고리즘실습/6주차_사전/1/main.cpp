#include<stdio.h>
#include<stdlib.h>

int findElement(int arr[],int l, int r, int k);

int main()
{
    int n, *A, key,num;

    scanf("%d %d", &n, &key);
    A = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    num = findElement(A,0, n-1, key);
    printf(" %d", num);

    free(A);
    return 0;
}

int findElement(int A[],int l, int r, int k)
{
    if (l > r)
    {
        if (r== -1)
            return -1;
        else
            return r;
    }
    if (A[(l+r) / 2] == k)
        return (l + r) / 2;

    if (A[(l + r) / 2] < k)
    {
        return findElement(A, (l + r) / 2 + 1, r, k);
    }
    if (A[(l + r) / 2] > k)
    {
        return findElement(A, l, (l + r) / 2 -1, k);
    }
}