//삽입식 힙생성

#include<stdio.h>

void swap(int *a, int *b);
void upHeap(int *H, int size);
void insertItem(int H[], int key, int *size);
void downHeap(int H[], int num, int size);
void Delete(int H[], int *size);
void Print(int *H, int n);

int main() {
    int key, H[100] = {0}, n = 0;
    char c;
    H[0] = 0;

    while (1) {
        scanf("%c", &c);
        getchar();

        switch (c) {
            case 'i':
                scanf("%d", &key);
                getchar();
                insertItem(H, key, &n);
                break;

            case 'd':
                Delete(H, &n);
                break;

            case 'p':
                Print(H, n);
                break;

            case 'q':
                return 0;

        }
    }
}
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void upHeap(int *H, int size)
{
    int tmp;
    while (1)
    {
        if (size != 1 && (H[size / 2] < H[size])){
            tmp = H[size];
            H[size] = H[size / 2];
            H[size / 2] = tmp;
            size /= 2;
        }
        else return;
    }
}
void insertItem(int H[], int key, int *size)
{
    (*size)++;
    H[*size] = key;
    upHeap(H, *size);
    printf("0\n");
    return;
}

void downHeap(int H[], int num, int size)
{
    int max;

    if (num * 2 > size && num * 2 + 1 > size){
        return;
    }
    max = num * 2;

    if (size >= num * 2 + 1){
        if(H[num*2+1]>H[max]){
            max = num * 2 + 1;
        }
    }
    if (H[num] > H[max]){
        return;
    }
    swap(&H[max], &H[num]);
    downHeap(H, max, size);
    return;
}
void Delete(int H[], int *size)
{
    swap(&H[*size], &H[1]);
    printf("%d\n", H[*size]);
    H[(*size)--] = 0;
    downHeap(H, 1, *size);
}
void Print(int *H, int n)
{
    int i = 1;

    while (i <= n)
    {
        printf(" %d", H[i++]);
    }
    printf("\n");
    return;
}