#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l,int r , int mid , int max)
{
	int *temp = (int*)malloc(sizeof(int)*(max));
	int i = l, j = mid+1;
	int k = l;
	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while (j <= r)
		temp[k++] = arr[j++];

	for (i = l; i <= r; i++)
		arr[i] = temp[i];
	return;
}
void mergeSort(int arr[], int l, int r , int max)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid, max);
		mergeSort(arr, mid + 1, r, max);
		merge(arr, l, r, mid, max);
	}
	return;
}
int main()
{
	int n;
	
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*(n));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0 ,n-1 , n);
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	return;
}
