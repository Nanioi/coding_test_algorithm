#include<stdio.h>
#include<stdlib.h>

int findElement(int *A, int l, int r, int k);

int main()
{
    int n, *A, key, num;

    scanf("%d %d", &n, &key);
    A = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    num = findElement(A, 0, n - 1, key);
    printf(" %d", num);

    free(A);
    return 0;
}

int findElement(int *A, int l, int r, int k)
{
    int n = r;

    while (l <= r)
    {
        if (A[(l + r) / 2] == k)
            return (l + r) / 2;

        if (k < A[(l + r) / 2])
        {
            r = (l + r) / 2 - 1;
        }
        if (A[(l + r) / 2] < k)
        {
            l = (l + r) / 2 +1;
        }
    }

    if (r == n)
        return n+1;
    else
        return l;
}