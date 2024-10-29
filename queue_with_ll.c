#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void push(node **front, node **rear, int val)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

void dequeue(node **front, node **rear)
{
    if (*front)
    {
        node *temp = *front;
        *front = (*front)->next;
        if (*front == NULL)
        {
            *rear = NULL;
        }
        free(temp);
    }
}

void display(node **front)
{
    node *temp = *front;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    node *front = NULL;
    node *rear = NULL;
    push(&front, &rear, 10);
    push(&front, &rear, 20);
    push(&front, &rear, 30);
    push(&front, &rear, 40);
    display(&front);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    display(&front);
    return 0;
}
