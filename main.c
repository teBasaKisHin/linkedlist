#include "LinkedList.h"
#include "stdio.h"

int main() {
    linkedList *list;

    list = initList();

    // insertList(&list, 1, 0);
    // insertList(&list, 2, 1);
    // insertList(&list, 3, 2);

    printList(list);

    freeList(list);
}
