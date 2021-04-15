8jm#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	FILE *fp;
	int n, cnt = 0, sum = 0;

	fp = fopen("data.txt", "w");

	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}

	scanf("%d", &n);

	while (!feof(stdin)) {
		fprintf(fp, "%d\n", n);
		scanf("%d", &n);
	}

	fclose(fp);

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}

	fscanf(fp, "%d", &n);

	while (!feof(fp))
	{
		sum += n;
		cnt++;
		fscanf(fp, "%d", &n);
	}
	printf("%d\n%d\n%.2lf", cnt, sum, (double)sum / cnt);
	fclose(fp);
	return 0;
}