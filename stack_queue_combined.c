#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void push(node* *top, int val) {
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL) {
        return;
    }
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

void pop(node* *top) {
    if (*top == NULL) {
        printf("Stack is empty, nothing to pop (underflow).\n");
        return;
    }
    node* temp = *top;
    *top = temp->next;
    printf("Popped value: %d\n", temp->data);
    free(temp);
}

void enqueue(node* *front, node* *rear, int val) {
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL) {
        return;
    }
    newnode->data = val;
    newnode->next = NULL;
    if (*front == NULL) {
        *front = *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

void dequeue(node* *front, node* *rear) {
    if (*front == NULL) {
        printf("Queue is empty, nothing to dequeue (underflow).\n");
        return;
    }
    node* temp = *front;
    *front = temp->next;
    printf("Dequeued value: %d\n", temp->data);
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void display(node* front) {
    node* temp = front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    printf("\n\nStack Operation\n\n");
    node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    display(top);
    pop(&top);
    display(top);

    printf("\n\nQueue Operation\n\n");
    node* front = NULL;
    node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);
    display(front);

    return 0;
}
