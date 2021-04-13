#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Tnode {
	struct Tnode* L;
	struct Tnode* R;
	int id;
	int data;
}Tnode;

Tnode* initTree();
int Calc(Tnode* T);

void main() {
	Tnode* F[9], * T = initTree();
	int m;

	for (int i = 0; i < 9; i++) {
		F[i] = initTree();
		F[i]->id = i + 1;
	}
	F[0]->data = 20;
	F[0]->L = F[1];
	F[0]->R = F[2];
	F[1]->data = 30;
	F[1]->L = F[3];
	F[1]->R = F[4];
	F[2]->data = 50;
	F[2]->R = F[5];
	F[3]->data = 70;
	F[4]->data = 90;
	F[5]->data = 120;
	F[5]->L = F[6];
	F[5]->R = F[7];
	F[6]->data = 130;
	F[7]->data = 80;

	scanf("%d", &m);
	for (int i = 0; i < 9; i++) {
		if (F[i]->id == m)
		{
			T = F[i];
			break;
		}
	}
	if (m > 8)
	{
		printf("-1");
		return;
	}
	printf("%d", Calc(T));
}

Tnode* initTree()
{
	Tnode* T = (Tnode*)malloc(sizeof(Tnode));
	T->data = -1;
	T->L = NULL;
	T->R = NULL;
	return T;
}
int Calc(Tnode* T)
{
	int left, right;
	if (T == NULL)
		return 0;
	else
	{
		left = Calc(T->L);
		right = Calc(T->R);
		return (left + right + T->data);
	}
	return 0;
}
