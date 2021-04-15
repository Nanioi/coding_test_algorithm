/*
	걸린시간: 17분
	자료구조개요: 재귀식 상향식 힙생성
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
void downHeap(int arr[], int n, int index)
{
	if (index * 2 > n && index * 2 + 1 > n) return;
	int max = index*2;
	if (arr[index * 2] < arr[index * 2 + 1])
		max = max + 1;
	if (arr[index] < arr[max])
	{
		swap(&arr[index], &arr[max]);
		downHeap(arr, n, max);
	}
	return;
}
void rebuildHeap(int arr[], int n, int index)
{
	if (index > 2*n) return;
	rebuildHeap(arr, n,2 * index);
	rebuildHeap(arr, n, 2 * index +1);
	downHeap(arr, n, index);
	return;
}
void printList(int arr[],int n)
{
	for (int i = 1; i <= n; i++)
		printf(" %d", arr[i]);
	return;
}
int main()
{
	int n;
	int arr[100] = { 0 };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	rebuildHeap(arr, n, 1);
	printList(arr, n);
	return;
	
}