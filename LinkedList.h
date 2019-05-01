#ifndef ___LinkedList
#define ___LinkedList

typedef struct cell {
    int num;
    int *nextCell;
    int *preCell;
} cell;

typedef struct linkedList {
    int *topCell;
    int *endCell;
    int size;
} linkedList;

linkedList initList(linkedList *list);

linkedList insertList(linkedList *list, int, int);

linkedList printList(linkedList *list);

linkedList clearList(linkedList *list);

// cell initCell(cell, int);

#endif // ___LinkedList