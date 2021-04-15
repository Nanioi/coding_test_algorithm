#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main()
{
	double result;
	int n[2], cnt = 0;

	scanf("%d %d",&n[0],&n[1]);

	if (n[0] == n[1])
	{
		result =(143+n[0]) / 153.0;
	}
	else
	{
		for (int i = 1;i <= 10;i++)
		{
			if (i == n[0] || i == n[1]) continue;
			for (int j = 1;j <= 10;j++)
			{
				if ((i + j) % 10 < (n[0] + n[1]) % 10 && i!=j)
					cnt++;
			}
	
		}
		cnt *= 2;
		result = cnt / 153.0;
	}
	printf("%.03f", result);
}