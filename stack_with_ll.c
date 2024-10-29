#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void push(node **top, int val)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        return;
    }
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

void pop(node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty, nothing to pop (underflow).\n");
        return;
    }
    node *temp = *top;
    *top = temp->next;
    printf("Popped value: %d\n", temp->data);
    free(temp);
}

void display(node **top)
{
    node *temp = *top;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    node *top = NULL;
   
    display(&top);
    pop(&top);
    display(&top);
    return 0;
}
