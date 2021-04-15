#include<stdio.h>
#include<stdio.h>
typedef struct temp
{
	int a, b;
}Temp;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
Temp partition(int arr[], int l, int r, int pivot)
{
	Temp temp;
	int i = l, j = r - 1;
	swap(&arr[pivot], &arr[r]);
	while (i <= j)
	{
		while (i <= j && arr[r] > arr[i])
		{
			i++;
		}
		while (i <= j && arr[r] <= arr[j])
		{
			j--;
		}
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	j = r - 1;
	temp.a = i;
	while (i <= j)
	{
		while (i <= j && arr[r] == arr[i])
		{
			i++;
		}
		while (i <= j && arr[r] < arr[j])
		{
			j--;
		}
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[r]);
	temp.b = i;
	return temp;
}
void quickSort(int arr[], int l, int r)
{
	Temp temp;
	if (l >= r) return;
	int pivot = (l + r) / 2;
	temp = partition(arr, l, r, pivot);
	quickSort(arr, l, temp.a-1);
	quickSort(arr, temp.b + 1, r);
	return;
}
int main()
{
	int n, *arr, i;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf(" %d", arr[i]);
	return;
}