#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct node {
    Point point;
    struct node *next;
} node;

typedef struct linkedList {
    node *head;
    node *tail;
} linkedList;

node *createNode(Point point);
node *insertFirst(linkedList *list, Point point);
node *insertLast(linkedList *list, Point point);
node *removeLast(linkedList *list);
void printList(node *head);
void freeList(linkedList *list) ;

#endif


