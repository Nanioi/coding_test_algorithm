#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct edge {
    int weight;
    int n1; int n2;
    struct edge *next;
}Edge;
int getunion(int set[], int a) {
    if (set[a] == a) return set[a];
    else return set[a] = getunion(set, set[a]);
}
void makeunion(int set[], int a, int b) {
    a = getunion(set, a);
    b = getunion(set, b);
    if (a > b) set[a] = b;
    else set[b] = a;
    return;
}
int parentunion(int set[], int a, int b) {
    a = getunion(set, a);
    b = getunion(set, b);
    if (a == b) return 1;
    else return 0;
}
void cruscal(Edge *edge, int set[]) {
    int sum = 0;
    while (edge->next != NULL) {
        if (parentunion(set, edge->next->n1, edge->next->n2) == 0) {
            sum = sum + edge->next->weight;
            makeunion(set, edge->next->n1, edge->next->n2);
            printf(" %d", edge->next->weight);
        }
        edge = edge->next;
    }
    printf("\n%d", sum);
    return;
}
int main() {
    int n, m, w, a,b;
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->weight = INT_MIN;
    edge->next = NULL;

    scanf("%d %d", &n, &m);
    int  *set = (int*)malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        set[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        Edge *e=edge;
        Edge *add = (Edge*)malloc(sizeof(Edge));
        add->next = NULL;
        while (e->next != NULL && e->next->weight < w) {
            e = e->next;
        }
        if (e->next != NULL) add->next = e->next;
        e->next = add;
        add->weight = w;
        add->n1 = a;
        add->n2 = b;
    }

    cruscal(edge, set);
    return 0;
}