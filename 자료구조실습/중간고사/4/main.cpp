#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 반 애들 출석부 만들기
typedef struct Node {
    struct Node *prev, *next;
    char *name;//이름
    int elem;
}node;
void initList(node **H, node **T);
node *newNode();
void addN(node *H, int r,char *str);
void DeleteN(node *H,char *str);
void getN(node *H, int r);
void PrintL(node *H);
int main(){
    node *H,*T,*p;
    int n,r;
    char str[10],c;
    initList(&H, &T);
    scanf("%d", &n);
    getchar();
    for (int i = 0;i < n;i++) {
        scanf("%c", &c);
        switch (c) {
            case 'A':
                scanf("%s %d", str,&r);//추가할 아이의 학생의 이름과 출석부 수 입력받기
                addN(H,r, str);
                break;
            case 'D':
                scanf("%s", str);//삭제하고 싶은 아이의 이름 입력
                break;
            case 'G':
                scanf("%d", &r);//r번째 학생 신상 출력
                getN(H, r);
                break;
            case 'P':
                PrintL(H);
                printf("\n");
                break;
        }
        getchar();
    }

    p = H;
    while (p != NULL) {
        p = H->next;
        free(H);
        H = p;
    }

}

void initList(node ** H, node ** T)
{
    (*H) = newNode();
    (*T) = newNode();
    (*H)->next = *T;
    (*T)->prev = *H;
    (*H)->elem= 1;
}

node *newNode()
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->prev = NULL;
    p->next = NULL;

    return p;
}

void addN(node * H, int r,char *str)
{
    node *p,*q;
    p = H;
    q=newNode();
    if (r < 1 || r>H->elem)
    {
        printf("invalid position\n");
        return -1;
    }
    for (int i = 0;i < r;i++) {
        p = p->next;
    }
    q->name = str;
    q->prev = p->prev;
    (p->prev)->next = q;
    q->next = p;
    p->prev = q;
    H->elem = H->elem+1;
}

void DeleteN(node * H, char *str)
{
    node *p;

    for (p=H;;p++) {
        if(p->next==NULL)
            break;
        if(strcmp(p->name,str)==0)
            break;
        p = p->next;
    }
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p);
    H->elem = H->elem - 1;
}
void getN(node * H, int r)
{
    node *p;
    p = H;
    if (r < 1 || r >= H->elem)
    {
        printf("invalid position\n");
        return -1;
    }
    for (int i = 0;i < r;i++)
        p = p->next;
    printf("%c \n", p->name);
}
void PrintL(node * H)
{
    node *p = H->next;
    while (p != NULL) {
        printf("%c \n", p->name);
        p = p->next;
    }
}