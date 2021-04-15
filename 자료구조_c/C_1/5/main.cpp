#include <stdio.h>
#pragma warning (disable:4996)

typedef struct time {
    int h, m, s;
}T;

int main()
{
    T t1, t2, t3;
    int x, y, z;

    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    x = t1.h * 3600 + t1.m * 60 + t1.s;
    y = t2.h * 3600 + t2.m * 60 + t2.s;

    if (x > y)
    {
        z = x - y;
        t3.h = z / 3600;
        t3.m = (z - 3600 * t3.h) / 60;
        t3.s = z % 60;
    }
    else
    {
        z = y-x;
        t3.h = z / 3600;
        t3.m = (z - 3600 * t3.h) / 60;
        t3.s = z % 60;
    }

    printf("%d %d %d", t3.h, t3.m, t3.s);
}