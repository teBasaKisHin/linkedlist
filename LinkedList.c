#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

cell initCell(cell *newCell, int data) {
    newCell = (cell *)malloc(sizeof(cell));
    newCell->num = data;
}

linkedList initList(linkedList *list) {
    list->topCell = NULL;
    // list->endCell = NULL;
    list->size = 0;

    // テスト
    cell newCell;
    initCell(&newCell, 0);
    newCell->preCell = NULL;
    newCell->nextCell = NULL;
}

linkedList freeList(linkedList *list) {
    cell *Cell;
    cell *next;

    Cell = list->topCell;
    next = Cell->nextCell;
    while(next->nextCell != NULL) {
        freeCell(Cell);
        Cell = next;
        next = Cell->nextCell;
    }
}

cell freeCell(cell *cell) {
    free(cell);
}

linkedList printList(linkedList *list) {
    printf("LinkedList size is %d\n", list->size);
    if(list->size == 0) {
        printf("Linked List is NULL\n");
        return;
    }
    
    cell *Cell;
    Cell = list->topCell;
    while(Cell->nextCell != NULL) {
        printf("%d ", Cell->num);
        Cell = Cell->nextCell;
    }
    putchar('\n');
}

// linkedList insertList(linkedList *list, int data, int pos) {
//     cell *newCellNode;

//     initCell(&newCellNode, data);
//     list->size++;

//     // リストが初期状態のときは先頭に代入
//     if (list->size == 0) {
//         pushFront(list, newCellNode, data);
//     } else if(list->size <= pos) { // 指定範囲がsizeより大きいときは最後に挿入
//         pushBack(list, newCellNode, data);
//     } else if(0 > pos) { // 指定範囲が0より小さいとき先頭に代入
//         pushFront(list, newCellNode, data);
//     } /* else { // 指定位置が1以上sizeより小さいとき
//         cell *node = list->topCell;
//         for(int i = 1; i < pos; i++) {
//             node = node->nextCell;
//         }

//         node = &newCellNode;
//         node->preCell = &newCellNode;
//     } */
// }

// linkedList pushFront(linkedList *list, cell *newCell, int data) {
//     newCell->nextCell = list->topCell;
//     newCell->preCell  = NULL;
//     list->topCell = &newCell;
// }

// linkedList pushBack(linkedList *list, cell *newCell,int data) {
//     newCell->nextCell = NULL;
//     newCell->preCell  = list->endCell;
//     list->endCell = &newCell;
// }

// linkedList push(linkedList *list, cell *newCell, int data, int pos) {

// }
