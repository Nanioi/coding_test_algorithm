#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b, n;
    char c;

    scanf("%d %d %d", &a, &b, &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        if (c == 'Y')
        {
            a = (a + b) / 2 + 1;
        }
        if (c == 'N')
        {
            b = (a + b) / 2;
        }
    }

    printf("%d", a);
    return 0;
}