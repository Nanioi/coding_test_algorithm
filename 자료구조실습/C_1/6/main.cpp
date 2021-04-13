#include<stdio.h>
#pragma warning (disable:4996)

typedef struct student {
    char name[10];
    int s;
}st;

int main()
{
    st s[5];
    int i = 0, sum = 0;
    double avg;

    scanf("%s %d", &s[0].name, &s[0].s);
    scanf("%s %d", &s[1].name, &s[1].s);
    scanf("%s %d", &s[2].name, &s[2].s);
    scanf("%s %d", &s[3].name, &s[3].s);
    scanf("%s %d", &s[4].name, &s[4].s);

    for (i = 0;i < 5;i++)
    {
        sum += s[i].s;
    }
    avg = (double)sum / 5;

    for (i = 0;i < 5;i++)
    {
        if (avg > s[i].s)
        {
            printf("%s\n", s[i].name);
        }
    }
}