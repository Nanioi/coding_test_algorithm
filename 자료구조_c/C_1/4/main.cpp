#include <stdio.h>

int main()
{
    char str[100];
    int i,tmp,cnt=0,re=0;

    scanf("%s",str);

    for(i=0;str[i];i++)
    {
        cnt++;
    }

    while(1)
    {
        printf("%s\n",str);

        for(i=0;i<cnt-1;i++)
        {
            tmp=str[i];
            str[i]=str[i+1];
            str[i+1]=tmp;
        }
        re++;

        if(re==cnt)
            break;

    }

}