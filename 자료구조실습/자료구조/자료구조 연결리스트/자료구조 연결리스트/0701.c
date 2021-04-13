#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
typedef struct node {
	int data;
	struct node *next;
}N;
void insert(N **head, int m_data);
void delete_data(N **head, int m_data);
void ShowAll(N *head);
//N *search(N *head, int m_data);
void sorting(N *head);

int main()
{
	int num,m_data;
	N *head = NULL;

	while(1)
	{
		printf("[1]추가 [2]삭제 [3]출력 [4]오름차순 [5]나가기\n");
		printf("번호 입력:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("추가할 데이터 입력:");
			scanf("%d", &m_data);
			insert(&head, m_data);
			system("cls");
			break;
		case 2:
			printf("삭제할 데이터 입력:");
			scanf("%d", &m_data);
			delete_data(&head, m_data);
			break;
		case 3:
			ShowAll(head);
			break;
		case 4:
			sorting(head);
			break;
		default:
			return;
		}
		
	}
}

void insert(N ** head, int m_data)
{

	if (*head == NULL)
	{
		*head = (N *)malloc(sizeof(N));
		(*head)->data = m_data;
		(*head)->next = NULL;
	}
	else
	{
		N *add;
		add = (N *)malloc(sizeof(N));

		add->next = *head;
		add->data = m_data;
		*head = add;

	}
}

void delete_data(N ** head, int m_data)
{
	N *p, *p_prev;
	int cnt = 0;

	p = *head;
	while(p != NULL) {
		if (cnt == 0)
		{
			if (p->data == m_data)
			{
				
				*head = p->next;
	      		free(p);
				return;
			}
		}
		else
		{
			p_prev = p;
			p = p->next;

			if (p->data == m_data)
			{
				p_prev->next = p->next;
				free(p);
				return;
			}
		}
		cnt++;
	}
}

void ShowAll(N * head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

/*
N *search(N * head, int m_data)
{
	while (head->next != NULL)
	{
		if (head->data == m_data)
		{
			return head;
			break;
		}
		else
			head = head->next;
	}
	return head;
}
*/

void sorting(N * head)
{
	N *p,*q, *q_prev,tmp;
	if (head == NULL) {
		return;
	}
	else
	{
		p = head;
		q_prev = head;
		q = q_prev->next;
		while (p != NULL)
		{
			while (q != NULL)
			{
				if (q_prev->data > q->data)
				{
					tmp.data = q_prev->data;
					q_prev->data = q->data;
					q->data = tmp.data;

				}
				q_prev = q;
				q = q->next;
			}
			p = p->next;
			q_prev = head;
			q = q_prev->next;
		}
	}
}
