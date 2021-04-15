#include <stdio.h>

void rprintDigits(int n){
    if(n<10)
        printf("%d\n",n);
    else
    {
        rprintDigits(n/10);
        printf("%d\n",n%10);
    }
}
int main(){
    int n;

    scanf("%d",&n);
    rprintDigits(n);
}