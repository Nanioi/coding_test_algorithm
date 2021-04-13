/*
시험대비
걸린 시간: 9분
자료구조 개요: 오른쪽부터 큰값을 채워 넣는 제자리 선택정렬
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void inplaceSelectionSort(int arr[], int n)
{
	int max, i,j;

	for (i = n - 1; i >= 0; i--)
	{
		max = i;
		for (j = i-1; j >= 0; j--)
		{
			if (arr[max] < arr[j])
			{
				swap(&arr[max], &arr[j]);	//수정: 이 부분을 첫번쨰 반복문뒤에 넣으면 연산을 줄일수있다.
			}
		}
	}
	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	inplaceSelectionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	free(arr);
	return;
}