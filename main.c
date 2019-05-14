#include "LinkedList.h"
#include "stdio.h"

int main() {
    linkedList *list;

    list = initList();

    pushFront(list, 0);
    pushFront(list, 1);
    pushBack(list, 2);
    insertList(list, -1, -1);
    insertList(list, 10, 2);

    printList(list);

    freeList(list);
}
