#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

typedef struct tmp
{
	Node *L1;
	Node *L2;
}Tmp;

Node *getNode();
void insertList(Node *header, int data);
Tmp mgPartition(Node *a, int n);
Node *merge(Node *L1, Node *L2);
void mergeSort(Node **header,  int n);
void printList(Node *header);
void freeList(Node *header);

int main()
{
	int n, data;
	Node *header=getNode();

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
    {
		scanf("%d", &data);
		insertList(header, data);
	}
	header = header->next;
	mergeSort(&header, n);
	printList(header);
	freeList(header);

	return 0;
}
Node *getNode()
{
    Node *h = (Node*)malloc(sizeof(Node));
    h->data=0;
    h->next = NULL;
    return h;
}
void insertList(Node *header, int data)
{
    Node *p,*q;
    p=header;
    while (p->next != NULL)
    {
        p = p->next;
    }
    q=getNode();
    q->data=data;
    p->next = q;
}
Tmp mgPartition(Node *a, int n)
{
    Tmp tmp;
    tmp.L1 = a;

    for (int i = 1; i < (n / 2); i++){
        a = a -> next;
    }
    tmp.L2 = a->next;

    if(n>1)
        a->next=NULL;

    return tmp;
}
Node *merge(Node *L1, Node *L2)
{
    Node *a=NULL;

    if (L2 == NULL)
        return L1;
    else if (L1 == NULL)
        return L2;

    if (L1->data < L2->data){
        a = L1;
        a->next = merge(L1->next, L2);
    }else{
        a = L2;
        a->next = merge(L2->next, L1);
    }

    return a;
}
void mergeSort(Node **header,  int n)
{
    Tmp tmp;

    if (n > 1)
    {
        tmp = mgPartition(*header, n);
        mergeSort(&tmp.L1, n / 2);

        if (n % 2 == 0)
            mergeSort(&tmp.L2,n/ 2);
        else
            mergeSort(&tmp.L2,(n/ 2) + 1);

        *header = merge(tmp.L1, tmp.L2);
    }

}
void printList(Node *header)
{
    while (header != NULL)
    {
        printf(" %d", header->data);
        header = header->next;
    }
    return;
}
void freeList(Node *header)
{
	if (header->next != NULL)
		freeList(header->next);
	free(header);
}