#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


node *createNode(Point point) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->point = point;
    newNode->next = NULL;
    return newNode;
}

node *insertFirst(linkedList *list, Point point) {
    node *newNode = createNode(point);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    return newNode;
}

node *insertLast(linkedList *list, Point point) {
    node *newNode = createNode(point);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    return newNode;
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("(%d,%d)->",temp->point.x, temp->point.y);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(linkedList *list) {
    node *currNode = list->head;
    node *temp;
    while (currNode != NULL) {
        temp = currNode;
        currNode = currNode->next;
        free(temp);
    }
    list->head = list->tail = NULL;
}

node *removeLast(linkedList *list) {
    node *prevNode = NULL;
    node *currNode = list->head;
    while (currNode != NULL && currNode->next != NULL) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        return NULL; // the list is empty
    }
    if (prevNode == NULL) {
        // the head node is the only node in the list
        list->head = list->tail = NULL;
    } else {
        // remove the last node from the list
        prevNode->next = NULL;
        list->tail = prevNode;
    }
    return currNode;
}


// int main() {
//     linkedList list;
//     list.head = NULL;
//     list.tail = NULL;
//     Point p1 = {1, 2};
//     Point p2 = {3, 4};
//     Point p3 = {5, 6};
//     Point p4 = {5, 3};


//     // Insert some nodes
//     insertLast(&list, p1); // tail should point to this node
//     insertLast(&list,p2); // tail should point to this node
//     insertLast(&list, p3); // tail should point to this node

//     // Print the list
//     printList(list.head);

//     // Remove the last node
//     removeLast(&list); // tail should now point to {3, 4}

//     // Print the list again
//     printList(list.head);

//     // Insert a node at the beginning
//     insertFirst(&list,p4); // tail should still point to {3, 4}

//     // Print the list one more time
//     printList(list.head);

//     printf("%d\n",list.tail->point.y);

//     // Free the memory used by the list
//     freeList(&list);

//     return 0;
// }