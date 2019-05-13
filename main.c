#include "LinkedList.h"
#include "stdio.h"

int main() {
    linkedList *list;

    list = initList();
    printf("Linked List was Created\n");

    // insertList(&list, 1, 0);
    // insertList(&list, 2, 1);
    // insertList(&list, 3, 2);

    printList(&list);

    freeList(&list);
}
