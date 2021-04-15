/*
�ɸ��ð�: 16��
�ڷᱸ�� ����: �պκ��� ���Ļ��·� �����ϴ� ��������
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
		{//����1: temp�� arr[i]�� �־����
			if (arr[j] >= arr[j-1])
			{
				break;
			}
			else
			{
				swap(&arr[j], &arr[j-1]);	//����1: ���⼭ ���Ҹ��� arr[j]=arr[j-1]���ϰ�
			}
		}
		//����1: ���⼭ arr[j] = temp�� ���ָ� ������ ���ϼ��ִ�.
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