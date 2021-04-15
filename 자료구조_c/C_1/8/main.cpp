#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct student {
    char name[8];
    int a, b, c;
    double avg;
    int flag;
}st;

int main()
{
    st *x;
    int n, i;

    scanf("%d", &n);
    getchar();

    x=(st *)malloc(sizeof(st)*n);

    for (i = 0;i < n;i++)
    {
        scanf("%s %d %d %d", &x[i].name, &x[i].a, &x[i].b, &x[i].c);
        x[i].avg = (x[i].a + x[i].b + x[i].c) / 3.0;
        x[i].flag=0;
    }

    for (i = 0;i < n;i++)
    {
        printf("%s %.1f", x[i].name, x[i].avg);

        if (x[i].a >= 90 || x[i].b >= 90 || x[i].c >= 90)
            x[i].flag=1;
        if(x[i].flag==1)
        {
            printf(" GREAT");
            x[i].flag=0;
        }
        if (x[i].a < 70 || x[i].b < 70 || x[i].c < 70)
            x[i].flag=1;
        if(x[i].flag==1)
        {
            printf(" BAD");
            x[i].flag=0;
        }
        printf("\n");

    }
}