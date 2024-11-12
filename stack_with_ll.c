#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val) {
    // Create new node
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    // Make the new node point to the top node
    newNode->next = top;
    // Update the top of the stack
    top = newNode;
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Popped element = %d\n", top->data);
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp = top;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    printf("Stack: ");
    display();
    pop();
    display();
    return 0;
}
