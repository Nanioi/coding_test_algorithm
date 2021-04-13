#include <stdio.h>
#include <stdlib.h>

void inPlaceSelectionSort(int *a,int n);
void swap(int *a,int *b);

int main(){
    int *a;
    int n;

    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    inPlaceSelectionSort(a,n);
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
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