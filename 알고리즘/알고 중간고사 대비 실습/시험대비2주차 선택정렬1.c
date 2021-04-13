/*
������
�ɸ� �ð�: 9��
�ڷᱸ�� ����: �����ʺ��� ū���� ä�� �ִ� ���ڸ� ��������
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
				swap(&arr[max], &arr[j]);	//����: �� �κ��� ù���� �ݺ����ڿ� ������ ������ ���ϼ��ִ�.
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