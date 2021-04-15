#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,**x;
    int i=0,j=0,flag=1,rM,cM,rm=0,cm=-1,c=1;

    scanf("%d %d",&n,&m);
    rM=n+1;
    cM=m;
    x=(int **)malloc(sizeof(int *)*n);
    for(int k=0;k<n;k++)
        x[k]=(int *)malloc(sizeof(int)*m);
    while((n*m)>=(c)){
        if(flag!=0)
        {
            x[i][j]=c;
            c++;
        } else
            flag++;
        if(flag==1)
        {
            j++;
            if(cM<=j)
            {
                flag++;
                j--;
                rM--;
            }
        }
        if(flag==2)
        {
            i++;
            if(rM<=i) {
                flag++;
                i--;
                cm++;
            }
        }
        if(flag==3)
        {
            j--;
            if(cm>j)
            {
                flag++;
                j++;
                rm++;
            }
        }
        if(flag==4)
        {
            i--;
            if(rm>i)
            {
                flag++;
                i++;
                cM--;
            }
        }
        if(flag>4)
            flag=0;

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %d",x[i][j]);
        }
        printf("\n");
    }
}
