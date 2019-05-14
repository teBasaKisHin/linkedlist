#ifndef ___LinkedList
#define ___LinkedList

typedef struct cell {
    int num;
    struct cell *nextCell;
    struct cell *preCell;
} cell;

typedef struct linkedList {
    int size;
    struct cell *topCell;
    // struct cell *endCell;
} linkedList;

linkedList *initList();

void freeList(linkedList *list);

// posの指定範囲は0から始める
linkedList insertList(linkedList *list, int, int);

void printList(linkedList *list);

// リストの先頭に挿入
linkedList pushFront(linkedList *list, cell *newCell, int);

// リストの終端に挿入
linkedList pushBack(linkedList *list, cell *newCell, int);

// リストの途中に挿入
linkedList push(linkedList *list, cell *newCell, int, int);

cell *initCell(int);

void freeCell(cell *cell);

#endif // ___LinkedList