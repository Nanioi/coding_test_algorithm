#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	FILE *fp1, *fp2;
	char fn1[21], fn2[21];
	int ch;
	int n, i;
	char str[100];

	scanf("%s", fn1);
	getchar();
	scanf("%s", fn2);

	fp1 = fopen(fn1, "a");
	fp2 = fopen(fn2, "r");

	if (fp1 == NULL || fp2 == NULL) {
		return -1;
	}

	ch = fgetc(fp2);
	while (!feof(fp2)) {
		fputc(ch, fp1);
		ch = fgetc(fp2);
	}
	/*
	fgets(str,sizeof(str),fp2);
	fputs(str,fp1);
	
	*/

	fclose(fp1);
	fclose(fp2);

}