/*
	걸린시간: 30분
	자료구조 개요: 키가 입력되자마자 즉시 힙에 삽입하여 명령어에 따른 동작을 하는
				   프로그램
				   배열을 이용한 힙정렬
				   MAX힙임
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
void upHeap(int arr[], int n)		//n=현노드의 인덱스값
{
	if (n <= 1) return;				//루트일경우 리턴
	if (arr[n] > arr[n / 2])		//루트노드가 현노드보다 작을경우(max힙기준)
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
//max힙 기준 다운힙
void downHeap(int arr[], int index, int n)			//index는 현노드위치(루트노드(index=1) 시작), n은 힙의 전체크기
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