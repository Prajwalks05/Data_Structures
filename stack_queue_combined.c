#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Stack operation here
node *top = NULL;

void push(int val)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    node *temp;

    if (top == NULL)
    {
        printf("Stack is Empty. Unable to perform pop\n");
    }
    else
    {
        temp = top;
        top = top->next;
        printf("Popped element: %d\n", temp->data);

        free(temp);
    }
}

void display_stack()
{
    node *temp = top;
    if (temp == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Queue operation here
node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty. Unable to perform dequeue\n");
    }
    else
    {
        temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        printf("Dequeued Element: %d\n", temp->data);
        free(temp);
    }
}

void display_queue()
{
    node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Stack operations
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Stack: ");
    display_stack();

    printf("Popping:\n");
    pop();
    pop();

    display_stack();

    // Queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("Queue: ");
    display_queue();

    printf("Dequeue\n");
    dequeue();
    dequeue();
    display_queue();

    return 0;
}
