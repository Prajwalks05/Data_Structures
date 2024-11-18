#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int data;
    struct Node *prev;
} node;

node *createNode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = val;
    newnode->prev = NULL;
    return newnode;
}

void insertbegin(node **head, int val)
{
    node *newnode = createNode(val);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void insertend(node **head, int val)
{
    node *newnode = createNode(val);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    node *temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertatPos(node **head, int position, int val)
{
    node *newnode = createNode(val);
    if (position == 1)
    {
        insertbegin(head, val);
        return;
    }

    node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    insertbegin(&head, 10);
    insertbegin(&head, 20);
    insertbegin(&head, 30);
    insertend(&head, 40);
    insertend(&head, 50);
    insertatPos(&head, 3, 25);
    display(head);
    return 0;
}
