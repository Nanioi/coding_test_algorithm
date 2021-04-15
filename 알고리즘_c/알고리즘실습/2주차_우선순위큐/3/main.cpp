#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void inPlaceInsertionSort(int *a,int n);
void inPlaceSelectionSort(int *a,int n);
void swap(int *a,int *b);

int main(){
    int *a,*b;
    int n;
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    scanf("%d",&n);

    a=(int *)malloc(sizeof(int)*n);
    b=(int *)malloc(sizeof(int)*n);
    srand(time(NULL));

    for(int i=0;i<n;i++)
    {
        a[i]=rand();
        b[i]=rand();
    }
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    inPlaceSelectionSort(a,n);
    inPlaceInsertionSort(b,n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart – start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    return 0;
}

void inPlaceInsertionSort(int *a,int n){
    int save,i,j;

    for(i=1;i<n;i++) {
        save = a[i];
        j = i - 1;
        while ((j >= 0) && a[j] > save) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = save;
    }
}
void inPlaceSelectionSort(int *a,int n){
    int min_i;

    for(int i=n-1;i>=0;i--){
        min_i=i;
        for(int j=i-1;j>=0;j--){
            if(a[j]>a[min_i])
                min_i=j;
        }
        swap(a+i,a+min_i);
    }
}
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}