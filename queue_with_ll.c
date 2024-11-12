#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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
        printf("Dequeued Element:%d\n", temp->data);
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("Queue: ");
    display();
    printf("Dequeue\n");
    dequeue();
    dequeue();
    display();

    return 0;
}
