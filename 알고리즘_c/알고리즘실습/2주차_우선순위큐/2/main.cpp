#include <stdio.h>
#include <stdlib.h>

void inPlaceInsertionSort(int *a,int n);

int main(){
    int *a;
    int n;

    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    inPlaceInsertionSort(a,n);
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
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