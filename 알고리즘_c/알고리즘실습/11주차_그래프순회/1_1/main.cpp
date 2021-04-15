#include <stdio.h>
#include <stdlib.h>

typedef struct vertices{
    int key;
    struct incidence *list;
    struct vertices *next;
}Vertex;
typedef struct edges{
    int path;
    struct vertices *start,*end;
    struct edges *next;
}Edge;
typedef struct incidence{
    struct edges *edge;
    struct incidence *next;
}Incidence;

Incidence *getincedence();
Vertex *getvertices();
Edge *getedges();
void addVertex(Vertex *header, int key);
Vertex *findVertex(Vertex *header, int key);
void addEdge(Vertex *header, Edge *edgeheader, int a, int b, int path);
void printAdjacency (Vertex *header, int key);
void deleteedges(Vertex *header, Edge *edgeheader, int a, int b);
int main(){

    char c;
    int key, a, b, path;

    Vertex *header = getvertices();
    addVertex(header, 1);
    addVertex(header, 2);
    addVertex(header, 3);
    addVertex(header, 4);
    addVertex(header, 5);
    addVertex(header, 6);

    Edge *edgeheader = getedges();
    addEdge(header, edgeheader, 1, 2, 1);
    addEdge(header, edgeheader, 1, 3, 1);
    addEdge(header, edgeheader, 1, 4, 1);
    addEdge(header, edgeheader, 1, 6, 2);
    addEdge(header, edgeheader, 2, 3, 1);
    addEdge(header, edgeheader, 3, 5, 4);
    addEdge(header, edgeheader, 5, 5, 4);
    addEdge(header, edgeheader, 5, 6, 3);

    while (1) {
        scanf("%c", &c);
        if (c == 'a') {
            scanf("%d", &key);
            printAdjacency(header, key);
        }
        else if (c == 'm') {
            scanf("%d %d %d", &a, &b, &path);
            if (path != 0)
                addEdge(header, edgeheader, a, b, path);
            else
                deleteedges(header, edgeheader, a, b);
        }
        else if (c == 'q') {
            break;
        }
        getchar();
    }
    return 0;
}
Incidence *getincedence() {
    Incidence *a = (Incidence*)malloc(sizeof(Incidence));
    a->edge = NULL;
    a->next = NULL;
    return a;
}
Vertex *getvertices() {
    Vertex *a = (Vertex *)malloc(sizeof(Vertex));
    a->next = NULL;
    Incidence *b = getincedence();
    a->list = b;
    return a;
}
Edge *getedges() {
    Edge *a = (Edge*)malloc(sizeof(Edge));
    a->start = NULL;
    a->end = NULL;
    a->next = NULL;
    return a;
}
void addVertex(Vertex *header, int key) {
    while (header->next != NULL) {
        header = header->next;
    }
    header->next = getvertices();
    header->next->key=key;
    return;
}
Vertex *findVertex(Vertex *header, int key) {
    Vertex *a = header;

    while (a != NULL && a->key != key) {
        a = a->next;
    }
    return a;
}
void addEdge(Vertex *header, Edge *edgeheader, int a, int b, int path){
    if (a > 6 || b > 6 || a < 1 || b < 1) {
        printf("-1\n");
        return;
    }
    Vertex *x=findVertex(header,a);
    Vertex *y=findVertex(header,b);

    while (edgeheader->next != NULL) {
        if (edgeheader->next->start == x &&edgeheader->next->end == y || edgeheader->next->start == y &&edgeheader->next->end == x) {
            edgeheader->next->path = path;
            return;
        }
        edgeheader = edgeheader->next;
    }
    edgeheader->next = getedges();
    edgeheader->next->path=path;
    edgeheader->next->start = x;
    edgeheader->next->end = y;
    edgeheader = edgeheader->next;

    Incidence *l1 = x->list;
    Incidence *l2 = y->list;
    Incidence *q;

    int num = 0;
    if (l1->next == NULL) {
        l1->next = getincedence();
        l1 = l1->next;
        l1->edge = edgeheader;
    }
    else {
        while (l1->next != NULL) {
            if (l1->next->edge->start->key == a)
                num = l1->next->edge->end->key;
            else
                num = l1->next->edge->start->key;
            if (num < b) {
                l1 = l1->next;
                if (l1->next == NULL) {
                    l1->next = getincedence();
                    l1 = l1->next;
                    l1->edge = edgeheader;
                    break;
                }
            }
            else {
                q = getincedence();
                q->next = l1->next;
                l1->next = q;
                q->edge = edgeheader;
                break;
            }
        }
    }
    if (x == y) {
        return;
    }
    else {
        if (l2->next == NULL) {
            l2->next = getincedence();
            l2 = l2->next;
            l2->edge = edgeheader;
        }
        else {
            while (l2->next != NULL) {
                if (l2->next->edge->start->key == b)
                    num = l2->next->edge->end->key;
                else
                    num = l2->next->edge->start->key;
                if (num < a) {
                    l2 = l2->next;
                    if (l2->next == NULL) {
                        l2->next = getincedence();
                        l2 = l2->next;
                        l2->edge = edgeheader;
                        break;
                    }
                }
                else {
                    q = getincedence();
                    q->next = l2->next;
                    l2->next = q;
                    q->edge = edgeheader;
                    break;
                }
            }
        }
    }
    return;
}

void printAdjacency (Vertex *header, int key) {
    Vertex *a = findVertex(header, key);

    if (a == NULL) {
        printf("-1\n");
        return;
    }
    Incidence *l = a->list;

    l = l->next;
    while (l != NULL) {
        if (l->edge->start->key != key) {
            printf(" %d", l->edge->start->key);
        }
        else
            printf(" %d", l->edge->end->key);

        printf(" %d", l->edge->path);
        if (l->next == NULL)
            break;
        else
            l = l->next;
    }
    printf("\n");
    return;
}
void deleteedges(Vertex *header, Edge *edgeheader, int a, int b) {

    while (edgeheader->next != NULL) {
        if (edgeheader->next->start->key == a && edgeheader->next->end->key == b || edgeheader->next->start->key == b && edgeheader->next->end->key == a) {
            break;
        }
        else
            edgeheader = edgeheader->next;
    }
    if (edgeheader->next == NULL) {
        printf("-1\n");
        return;
    }
    Edge *deleteEdge = edgeheader->next;
    Incidence *x = deleteEdge->start->list;
    Incidence *y = deleteEdge->end->list;
    Incidence *tmp;
    while (x->next != NULL) {
        if (x->next->edge == deleteEdge) {
            tmp = x->next;
            if (tmp->next == NULL) {
                x->next = NULL;
                break;
            }
            x->next = tmp->next;
        }
        x = x->next;
    }
    free(tmp);
    if (a != b) {
        while (y->next != NULL) {
            if (y->next->edge == deleteEdge) {
                tmp = y->next;
                if (tmp->next == NULL) {
                    y->next = NULL;
                    break;
                }
                y->next = tmp->next;
            }
            y = y->next;
        }
        free(tmp);
    }
    if (deleteEdge->next == NULL) {
        edgeheader->next = NULL;
    }
    else {
        edgeheader->next = deleteEdge->next;
    }
    free(deleteEdge);
    return;
}