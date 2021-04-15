#include<stdio.h>
#include<stdlib.h>
typedef struct temp
{
	int a;
	int b;
}Temp;
void swap(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
	return;
}
int partition(int arr[], int l, int r, int pivot)
{
	int i, j;
	i = l;
	j = r - 1;
	swap(&arr[pivot], &arr[r]);
	while (i <= j)
	{
		while (i <= j && arr[r] >= arr[i])
		{
			i++;
		}
		while (i <= j && arr[r] <= arr[j])
		{
			j--;
		}
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
void quickSort(int arr[], int l, int r)
{
	if (l >= r) return;
	int pivot = (l + r) / 2;
	pivot = partition(arr, l, r, pivot);
	quickSort(arr, l, pivot-1);
	quickSort(arr, pivot + 1, r);
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
	
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	return;
}