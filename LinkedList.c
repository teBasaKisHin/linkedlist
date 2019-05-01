#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

linkedList initList(linkedList *list) {
    list->topCell = NULL;
    list->endCell = NULL;
    list->size = 0;
}

linkedList insertList(linkedList *list, int data, int pos) {
    cell *newCellNode;
    newCellNode = (cell *)malloc(sizeof(cell));
    newCellNode->num = data;
    list->size++;

    // リストが初期状態のとき
    if (list->size == 0) {
        newCellNode->nextCell = newCellNode->preCell = NULL;

        list->topCell = &newCellNode;
        list->endCell = &newCellNode;
    } else if(list->size <= pos) { // 指定範囲がsizeより大きいときは最後に挿入
        newCellNode->nextCell = NULL;
        newCellNode->preCell  = list->endCell;

        list->endCell = *newCellNode;
    } else if(0 > pos) { // 指定範囲が0より小さいとき先頭に代入
        newCellNode->nextCell = list->topCell;
        newCellNode->preCell  = NULL;

        list->topCell = *newCellNode;
    } else {
        cell node = topCell;
        for(int i = 1; i < pos; i++) {
            node = node->nextCell;
        }

        cell nextNode, preNode;
        nextNode = node;
        preNode = node->preCell;

        preNode->nextCell = newCellNode;
        nextNode->preCell = newCellNode;
    }
}

linkedList printList(linkedList list) {
    cell *node;
    node = list->topCell;
    while(node->nextCell == NULL) {
        printf("%d ", node->num);
    }
    putchar('\n');
}

linkedList clearList(linkedList list) {

}
