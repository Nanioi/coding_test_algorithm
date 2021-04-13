/*
걸린시간: 16분
자료구조 개요: 앞부분을 정렬상태로 유지하는 삽입정렬
*/

#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void inplaceSertionSort(int arr[], int n)
{
	int max;
	int i, j;
	for (i = 1; i < n; i++)
	{
		max = i;
		for (j = i; j >= 1; j--)
		{//수정1: temp에 arr[i]를 넣어놓고
			if (arr[j] >= arr[j-1])
			{
				break;
			}
			else
			{
				swap(&arr[j], &arr[j-1]);	//수정1: 여기서 스왑말고 arr[j]=arr[j-1]만하고
			}
		}
		//수정1: 여기서 arr[j] = temp를 해주면 연산을 줄일수있다.
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
	inplaceSertionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	free(arr);
	return;
}