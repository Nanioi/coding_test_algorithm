#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct vertices {
    int name;
    int incnt;
    struct incidence *inlist;
    struct incidence *outlist;
    struct vertices *next;
}Vertices;
typedef struct edges {
    struct vertices *first, *end;
    struct edges *next;
}Edges;
typedef struct incidence {
    struct edges *edge;
    struct incidence *next;
}Incidence;
typedef struct Queue {
    struct vertices *now;
    struct Queue *next;
}queue;

queue *getqueue();
Incidence *getincedence();
Vertices *getvertices(int num);
Edges *getedges();
Vertices *findvertices(Vertices *header, int num);
void addvertices(Vertices *header, int num);
void addedges(Vertices *header, Edges *eheader, int a, int b);
int topologicalSort(queue *outputQue, Vertices *vheader, int n);

int main() {
    Vertices *vheader = getvertices(INT_MAX);
    Edges *eheader = getedges();

    char vertax, node1, node2;
    int n, m;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &vertax);
        getchar();
        addvertices(vheader, vertax);
    }
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++) {
        scanf("%c %c", &node1, &node2);
        getchar();
        addedges(vheader, eheader, node1, node2);
    }
    queue *outputQue = getqueue();
    if (topologicalSort(outputQue, vheader, n)) {
        while (outputQue->next != NULL) {
            printf("%c ", outputQue->next->now->name);
            outputQue = outputQue->next;
        }
    }
    else {
        printf("0\n");
    }
    return 0;
}
queue *getqueue() {
    queue *a = (queue *)malloc(sizeof(queue));
    a->now = NULL;
    a->next = NULL;
    return a;
}
Incidence *getincedence() {
    Incidence *a = (Incidence*)malloc(sizeof(Incidence));
    a->edge = NULL;
    a->next = NULL;
    return a;
}
Vertices *getvertices(int num) {
    Vertices *a = (Vertices*)malloc(sizeof(Vertices));
    a->name = num;
    a->next = NULL;
    a->incnt = 0;
    a->inlist = getincedence();
    a->outlist = getincedence();
    return a;
}
Edges *getedges() {
    Edges *a = (Edges*)malloc(sizeof(Edges));
    a->first = NULL;
    a->end = NULL;
    a->next = NULL;
    return a;
}
Vertices *findvertices(Vertices *header, int num) {
    Vertices *a = header;
    while (a != NULL && a->name != num) {
        a = a->next;
    }
    return a;
}
void addvertices(Vertices *header, int num) {
    while (header->next != NULL) {
        header = header->next;
    }
    header->next = getvertices(num);
    return;
}
void addedges(Vertices *header, Edges *eheader, int a, int b) {

    Vertices *node1 = findvertices(header, a);
    Vertices *node2 = findvertices(header, b);


    Edges *newedge = getedges();
    if (eheader->next != NULL) {
        newedge->next = eheader->next;
    }
    eheader->next = newedge;
    newedge->first = node1;
    newedge->end = node2;


    Incidence *list1 = node1->outlist;
    Incidence *list2 = node2->inlist;
    Incidence *in = getincedence();
    Incidence *out = getincedence();


    if (list1->next != NULL && list1->next->edge->first->name > newedge->first->name) {
        list1 = list1->next;
    }
    if (list1->next != NULL) {
        out->next = list1->next;
    }
    list1->next = out;
    out->edge = newedge;

    if (list2->next != NULL && list2->next->edge->end->name > newedge->end->name) {
        list2 = list2->next;
    }
    if (list2->next != NULL) {
        in->next = list2->next;
    }
    list2->next = in;
    in->edge = newedge;

    node2->incnt++;
    return;
}
int topologicalSort(queue *outputQue, Vertices *vheader, int n) {
    queue *queheader = getqueue();
    queue *que = queheader;
    int tcnt = 1;

    for (int i = 0; i < n; i++) {
        vheader = vheader->next;
        if (vheader->incnt == 0) {
            queue *a = getqueue();
            a->now = vheader;
            que->next = a;
            que = que->next;
        }
    }
    while (queheader->next != NULL) {
        queue *a = getqueue();
        a->now = queheader->next->now;
        outputQue->next = a;
        outputQue = outputQue->next;
        tcnt++;
        Incidence *outlist = outputQue->now->outlist;
        outlist = outlist->next;
        while(outlist != NULL) {
            Vertices *w = outlist->edge->end;
            w->incnt--;
            if (w->incnt == 0) {
                queue *b = getqueue();
                b->now = w;
                que->next = b;
                que = que->next;
            }
            outlist = outlist->next;
        }
        queheader = queheader->next;
    }
    if (tcnt <= n) return 0;
    else return 1;
}