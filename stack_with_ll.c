#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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
        printf("Popped element:%d\n", temp->data);

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

int main()
{
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

    return 0;
}
