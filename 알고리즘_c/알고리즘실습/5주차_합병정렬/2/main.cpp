#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct range
{
    int a;
    int b;
}Range;

void swap(int *a, int *b);
int find_pivot_index( int L[],int l, int r);
Range inPlacePartition(int L[], int l, int r, int k);
void inPlaceQuickSort(int L[], int l, int r);

int main()
{
    int n,*L;

    scanf("%d", &n);
    L = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }

    inPlaceQuickSort(L, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf(" %d", L[i]);
    }

    return 0;
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}
int find_pivot_index(int L[], int l, int r)
{
    int a[3];

    srand((unsigned)time(NULL));

    for (int i = 0; i < 3; i++)
    {
        a[i] = rand() % (r - l+1) + l;
    }
    if (L[a[0]] > L[a[1]]){
        if (L[a[1]] > L[a[2]])
            return a[1];
        else if (L[a[0]] > L[a[2]])
            return a[2];
        else
            return a[0];
    }
    else{
        if (L[a[0]] > L[a[2]])
            return a[0];
        else if (L[a[1]] > L[a[2]])
            return a[2];
        else
            return a[1];
    }
}
Range  inPlacePartition(int L[], int l, int r, int k){

    Range R;
    swap(L+r, L+k);
    int i = l, j = r - 1;

    while (i <= j)
    {
        while(i <= j && L[i] < L[r])
        {
            i ++;
        }
        while(i<=j && L[j] >= L[r])
        {
            j --;
        }
        if(i<j) {
            swap(L + i, L + j);
        }
    }
    R.a = i;
    j = r - 1;

    while (i <= j)
    {
        while (i <= j && L[i] == L[r])
        {
            i ++;
        }
        while (i <= j && L[j] > L[r])
        {
            j --;
        }
        if(i<j) {
            swap(L+i, L+j);
        }
    }
    swap(L+i, L+r);
    R.b = i;

    return R;
}
void inPlaceQuickSort(int L[], int l, int r)
{
    int k;
    Range R;

    if (l >= r) return;

    k = find_pivot_index(L,l,r);
    R = inPlacePartition(L, l, r, k);

    inPlaceQuickSort(L, l, R.a-1);
    inPlaceQuickSort(L, R.b +1, r);

    return;
}