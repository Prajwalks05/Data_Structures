#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void insertAtBeginning(node **head, int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

void display(node **head) {
    node *temp = *head;
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void countNode(node **head, int *count) {
    node *temp = *head;
    *count = 0;
    while (temp != NULL) {
        (*count)++;
        temp = temp->next;
    }
    printf("number of nodes in list: %d\n", *count);
}

void printMiddle(node **head, int count) {
    node *temp = *head;
    int middle = count / 2;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }
    printf("middle of element: %d\n", temp->data);
}

void main() {
    node *head = NULL;
    int count = 0;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    display(&head);
    countNode(&head, &count);
    printMiddle(&head, count);
}
