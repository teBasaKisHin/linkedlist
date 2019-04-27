#ifndef ___LinkedList
#define ___LinkedList

typedef struct linkedList {
    int num;
    int nextPoint;
    int prePoint;
} linkedList;

linkedList initList(int []);

linkedList insertList(linkedList, int);

linkedList printList(linkedList);

#endif // ___LinkedList