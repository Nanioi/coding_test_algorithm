#include <stdio.h>
#include <stdlib.h>

typedef struct vertices{
    int key;
    struct vertices *next;
}Vertex;
typedef struct edges{
    struct vertices *start,*end;
    struct edges *next;
}Edge;
typedef struct array{
    int path;
    struct edges *edge;
}Array;

Vertex *getvertices();
Edge *getedges();
Vertex *findVertex(Vertex *header, int key);
void addEdge(Vertex *header, Edge *edgeheader,Array **array, int a, int b, int path);
void printAdjacency (Array **array, int key);

int main(){

    Array **array = (Array**)malloc(sizeof(Array*) * 7);
    for (int i = 0; i < 7; i++) {
        array[i] = (Array*)malloc(sizeof(Array) * 7);
        for (int j = 0; j < 7; j++) {
            array[i][j].path = 0;
        }
    }

    Vertex *header = getvertices();
    Vertex *tmp = header;
    for (int i = 0; i < 6; i++) {
        tmp->next = getvertices();
        tmp->next->key=i+1;
        tmp = tmp->next;
    }
    Edge *edgeheader = getedges();
    addEdge(header, edgeheader, array, 1, 2, 1);
    addEdge(header, edgeheader, array, 1, 3, 1);
    addEdge(header, edgeheader, array, 1, 4, 1);
    addEdge(header, edgeheader, array, 1, 6, 2);
    addEdge(header, edgeheader, array, 2, 3, 1);
    addEdge(header, edgeheader, array, 3, 5, 4);
    addEdge(header, edgeheader, array, 5, 5, 4);
    addEdge(header, edgeheader, array, 5, 6, 3);

    char c;
    int key, a, b, path;
    while (1) {
        scanf("%c", &c);
        if (c == 'a') {
            scanf("%d", &key);
            printAdjacency(array, key);
        }
        else if (c == 'm') {
            scanf("%d %d %d", &a, &b, &path);
            addEdge(header, edgeheader, array, a, b, path);
        }
        else if (c == 'q') {
            break;
        }
        getchar();
    }
    return 0;
}
Vertex *getvertices() {
    Vertex *a = (Vertex *)malloc(sizeof(Vertex));
    a->next = NULL;
    return a;
}
Edge *getedges() {
    Edge *a = (Edge*)malloc(sizeof(Edge));
    a->start = NULL;
    a->end = NULL;
    a->next = NULL;
    return a;
}
Vertex *findVertex(Vertex *header, int key) {
    Vertex *a = header;

    while (a != NULL && a->key != key) {
        a = a->next;
    }
    return a;
}
void addEdge(Vertex *header, Edge *edgeheader, Array **array, int a, int b, int path){
    Vertex *x = findVertex(header, a);
    Vertex *y = findVertex(header, b);

    if (x == NULL || y == NULL) {
        printf("-1\n");
        return;
    }
    if (array[a][b].path == 0) {
        while (edgeheader->next != NULL) {
            edgeheader = edgeheader->next;
        }
        edgeheader->next = getedges();
        edgeheader->next->start = x;
        edgeheader->next->end = y;
        array[a][b].edge = edgeheader->next;
        array[b][a].edge = edgeheader->next;
    }
    array[a][b].path = path;
    array[b][a].path = path;

    return;
}

void printAdjacency(Array **array, int key) {
    int i;
    if (key > 6 || key < 1) {
        printf("-1\n");
        return;
    }
    for (i = 1; i < 7; i++) {
        if (array[key][i].path != 0) {
            printf(" %d %d", i, array[key][i]);
        }
    }
    printf("\n");
    return;
}