#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Member {
	char name[20];
	char number[15];
	char hb[9];
}MP;

void input(char *p)
{
	scanf("%s", p);
}

void ShowAll(MP *p, int n)
{
	MP *q;

	for (q = p;q < p + n - 1;q++)
	{
		printf("%s %s %s\n", q->name, q->number, q->hb);
	}
}

void delete(MP *p)
{
	strcpy(p->name, "\0");
	strcpy(p->number, "\0");
	strcpy(p->hb, "\0");
}
int main()
{
	MP x[100], *p = x, tmp, *a;
	int n, cnt = 1, flag = 0;
	char dname[20], fhb[9];

	while (1) {
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &n);

		if (n == 1)
		{
			printf("Name:");
			input(p->name);

			printf("Phone_number:");
			input(p->number);

			printf("Birth:");
			input(p->hb);

			if (cnt >= 100)
			{
				printf("OVERFLOW\n");
				continue;
			}
			if (cnt >= 2)
			{
				if (strcmp(p->name, (p - 1)->name) < 0)
				{
					tmp = *p;
					*p = *(p - 1);
					*(p - 1) = tmp;
				}
			}

			printf("<<%d>>\n", cnt);
			p++;
			cnt++;
		}
		else if (n == 2)
		{
			if (cnt == 1)
				continue;
			else
			{
				ShowAll(x, cnt);
			}
		}
		else if (n == 3)
		{
			if (cnt == 1)
			{
				printf("NO MEMBER\n");
				continue;
			}
			else
			{
				printf("Name:");
				input(dname);

				flag = 0;
				for (a = x;a < x + cnt - 1;a++)
				{
					if (strcmp(a->name, dname) == 0)
					{
						flag = 1;
						delete(a);
						break;
					}
				}
				if (flag == 0)
				{
					printf("NO MEMBER\n");
					continue;
				}
			}
		}
		if (n == 4)
		{
			printf("Birth:");
			input(fhb);

			for (a = x;a < x + cnt - 1;a++)
			{
				if (strcmp(a->hb, fhb) == 0)
				{
					printf("%s %s %s\n", a->name, a->number, a->hb);
				}
			}
		}
		if (n == 5)
			break;
	}
}
