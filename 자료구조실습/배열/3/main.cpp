#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,**x,c=0;
    scanf("%d",&n);
    x=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        x[i]=(int *)malloc(sizeof(int)*n);
        if(i%2==0) {
            for (int j = 0; j < n; j++) {
                c++;
                x[i][j]=c;
            }
        } else
            for(int j= n-1;j>=0;j--){
                c++;
                x[i][j]=c;
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            printf(" %d",x[i][j]);
        }
        printf("\n");
    }
}