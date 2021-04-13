/*
	�ɸ��ð�: 30��
	�ڷᱸ�� ����: Ű�� �Էµ��ڸ��� ��� ���� �����Ͽ� ��ɾ ���� ������ �ϴ�
				   ���α׷�
				   �迭�� �̿��� ������
				   MAX����
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
void upHeap(int arr[], int n)		//n=������� �ε�����
{
	if (n <= 1) return;				//��Ʈ�ϰ�� ����
	if (arr[n] > arr[n / 2])		//��Ʈ��尡 ����庸�� �������(max������)
	{
		swap(&arr[n], &arr[n / 2]);
		upHeap(arr, n / 2);
	}
	return;
}
void insertItem(int arr[], int key, int n)
{
	arr[n] = key;

	upHeap(arr, n);
	printf("0\n");
	return;
}
//max�� ���� �ٿ���
void downHeap(int arr[], int index, int n)			//index�� �������ġ(��Ʈ���(index=1) ����), n�� ���� ��üũ��
{
	//if (index > n) return;
	if (index * 2 > n && index * 2 + 1 > n) return;
	int maxindex = 0;
	maxindex = index * 2;
	if (arr[index * 2] < arr[index * 2 + 1])
	{
		maxindex = index * 2 + 1;
	}
	if (arr[index] < arr[maxindex])					//
	{
		swap(&arr[index], &arr[maxindex]);
		downHeap(arr, maxindex, n);
	}
	return;
}
void deleteItem(int arr[], int n)
{
	swap(&arr[1], &arr[n + 1]);
	printf("%d\n", arr[n + 1]);
	arr[n + 1] = 0;

	downHeap(arr, 1, n);
	return;
}
void printList(int arr[], int n)
{
	for (int i = 1; i <= n; i++ ) 
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	return;
}
int main()
{
	int arr[100] = { 0 };
	int n=0, key=0;
	char command;

	while (1)
	{

		scanf("%c", &command);
		getchar();
		if (command == 'i')
		{
			scanf("%d", &key);
			getchar();
			n++;
			insertItem(arr, key , n);
		}
		if (command == 'd')
		{
			n--;
			deleteItem(arr, n);
		}
		if (command == 'p')
		{
			printList(arr, n);
		}
		if (command == 'q')
		{
			return 0;
		}
		
	}


}