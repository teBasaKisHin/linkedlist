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

    // 現在のセル
    cell *cellNode;
} linkedList;

linkedList initList(linkedList);

linkedList insertList(linkedList, int, int);

linkedList printList(linkedList);

linkedList clearList(linkedList);

// cell initCell(cell, int);

#endif // ___LinkedList