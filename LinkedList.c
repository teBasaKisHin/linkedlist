#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

linkedList *initList() {
    linkedList *list;

    list = (linkedList *)malloc(sizeof(linkedList));

    if(list == NULL) {
        printf("メモリの取得エラー\n");
        return NULL;
    }

    list->topCell = NULL;
    list->size = 0;

    printf("Linked List was Created.\n");
    return list;
}

void freeList(linkedList *list) {
    cell *Cell = NULL;
    cell *preCell = NULL;

    if(list == NULL) {
        printf("リストがNULLです\n");
        return;
    }

    Cell = list->topCell;
    while(Cell != NULL) {
        preCell = Cell;
        Cell = preCell->nextCell;
        freeCell(preCell);
    }
    
    printf("リストの開放の完了\n");
    free(list);
}

void freeCell(cell *cell) {
    free(cell);
    // printf("セルの開放が完了\n");
}

void printList(linkedList *list) {
    if(list == NULL) {
        printf("リストが定義されていません");
        return;
    }
    if(list->size == 0) {
        printf("リストは空です\n");
        return;
    }
    
    printf("LinkedList size is %d\n", list->size);
    cell *Cell = list->topCell;
    while(Cell != NULL) {
        printf("%d ", Cell->num);
        Cell = Cell->nextCell;
    }
    putchar('\n');
}

cell *initCell() {
    cell *newCell = NULL;
    newCell = (cell *)malloc(sizeof(cell));

    if(newCell == NULL) {
        printf("メモリの取得に失敗\n");
        return NULL;
    }
    return newCell;
}

void pushFront(linkedList *list, int data) {
    if(list == NULL) {
        printf("リストが定義されていません\n");
        return;
    }
    cell *newCell = initCell(data);
    if(newCell == NULL) {
        printf("リストの追加に失敗\n");
        return;
    }

    if(list->size == 0)
    {
        newCell->nextCell = NULL;
        newCell->preCell = NULL;
    }
    else if(list->size > 0)
    {
        cell *nextCell = list->topCell;
        newCell->nextCell = nextCell;
        newCell->preCell = NULL;
        nextCell->preCell = newCell;
    }

    newCell->num = data;
    list->size++;
    list->topCell = newCell;
    printf("先頭のセルの追加に成功 %d\n", newCell->num);
}

void pushBack(linkedList *list,int data) {
    if(list == NULL) {
        printf("リストが定義されていません\n");
        return;
    }
    cell *newCell = initCell(data);
    if(newCell == NULL) {
        printf("リストの追加に失敗\n");
        return;
    }

    newCell->nextCell = NULL;
    if(list->size == 0)
    {
        newCell->preCell = NULL;
        list->topCell = newCell;
    }
    else if(list->size > 0)
    {
        // 最後のセルを探索
        cell *endCell = list->topCell;
        while(endCell->nextCell != NULL) {
            endCell = endCell->nextCell;
        }
        newCell->preCell = endCell;
        endCell->nextCell = newCell;
    }

    newCell->num = data;
    list->size++;
    printf("末尾のセルの追加に成功 %d\n", newCell->num);
}

void insertList(linkedList *list, int data, int pos) {
    if(list == NULL) {
        printf("リストが定義されていません\n");
        return;
    }

    if(list->size <= pos) { // 指定範囲がsizeより大きいときは最後に挿入
        pushBack(list, data);
    } else if(0 >= pos) { // 指定範囲が0より小さいとき先頭に代入
        pushFront(list, data);
    } else { // 指定位置が1以上sizeより小さいとき
        cell *newCell = initCell(data);
        if(newCell == NULL) {
            printf("リストの追加に失敗\n");
            return;
        }
        cell *preCell = list->topCell;
        for(int i = 1; i < pos - 1; i++) {
            preCell = preCell->nextCell;
        }
        cell *nextCell = preCell->nextCell;

        preCell->nextCell = newCell;
        newCell->preCell = preCell;
        newCell->nextCell = nextCell;
        nextCell->preCell = newCell;

        newCell->num = data;
        printf("%dのセルの追加に成功 %d\n", pos, newCell->num);
    }
}
