// rbuildHeap 사용

#include<stdio.h>

void swap(int *a, int *b);
void upHeap(int *H, int size);
void insertItem(int H[], int key, int size);
void downHeap(int H[], int num, int size);
void printArray(int *H, int n);
void rBuildHeap(int H[], int n, int i);
void buildHeap(int H[], int n);
void inPlaceHeapSort(int H[],int n);

int main() {
    int key,H[100] = {0}, n;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&key);
        insertItem(H,key,i);
    }
    inPlaceHeapSort(H,n);
    printArray(H,n);

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
void upHeap(int *H, int size)
{
    int tmp;
    while (1)
    {
        if (size != 1 && (H[size / 2] < H[size])){
            tmp = H[size];
            H[size] = H[size / 2];
            H[size / 2] = tmp;
            size /= 2;
        }
        else return;
    }
}
void insertItem(int H[], int key, int size)
{
    H[size] = key;
    upHeap(H, size);
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
void printArray(int *H, int n)
{
    int i = 1;

    while (i <= n)
    {
        printf(" %d", H[i++]);
    }
    printf("\n");
    return;
}
void rBuildHeap(int H[], int n, int i)
{
    if (i > n)
    {
        return;
    }

    rBuildHeap(H, n, 2*i);
    rBuildHeap(H, n, 2 * i + 1);
    downHeap(H, i, n);
    return;
}
void buildHeap(int H[], int n)
{
    for(int i=n/2;i>=1;i-- ){
        downHeap(H,i,n);
    }
    return;
}
void inPlaceHeapSort(int H[],int n){
    rBuildHeap(H,n,1);
    for(int i=n;i>1;i--){
        swap(H+1,H+i);
        downHeap(H,1,i-1);
    }
    return;
}