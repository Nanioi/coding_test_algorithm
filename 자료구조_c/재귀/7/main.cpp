#include <stdio.h>
#include <string.h>

int count(char *s,char c,int n,int cnt){

    if(s[n]=='\0')
        return cnt;
    else{
        if(s[n]==c)
            cnt++;
        count(s,c,n+1,cnt);
    }

}
int main(){
    char str[100],c;
    int n=0,cnt=0;

    scanf("%s",str);
    getchar();
    scanf("%c",&c);

    printf("%d",count(str,c,n,cnt));

}