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

// posの指定範囲は0から始める
linkedList insertList(linkedList *list, int, int);

linkedList printList(linkedList *list);

linkedList clearList(linkedList *list);

// リストの先頭に挿入
linkedList pushFront(linkedList *list, cell *newCell, int);

// リストの終端に挿入
linkedList pushBack(linkedList *list, cell *newCell, int);

// リストの途中に挿入
linkedList push(linkedList *list, cell *newCell, int, int);

cell initCell(cell *newCell, int);

#endif // ___LinkedList