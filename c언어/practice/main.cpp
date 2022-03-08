#include <stdio.h>
#include <stdlib.h>

int check(int n, int candy[]){
    int flag = 1;
    int k = candy[0];
    for(int i=0;i<n;i++){
        if(candy[i]%2 == 1){
            candy[i]+=1;
        }
        if (candy[i]!=k){
            flag = 0;
        }
    }
    return flag;
}
void teacher(int n, int candy[]){

    int *tmp;
    tmp = (int *)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++){
        if (candy[i] %2==1){
            candy[i]+=1;
        }
        candy[i] = candy[i]/2;
        tmp[(i+1)%n] = candy[i];
    }

    for (int i=0;i<n;i++){
        candy[i]+=tmp[i];
    }
}
void process(){
    int num,*candy;

    scanf("%d",&num);
    candy = (int *)malloc(sizeof(int)*num);

    for(int i=0;i<num;i++){
        scanf("%d ",&candy[i]);
    }

    int cnt=0;
    int collect = check(num,candy);
    while(collect<1)
    {
        cnt+=1;
        teacher(num,candy);
    }
    printf("%d\n",cnt);
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        process();
    }

    return 0;
}