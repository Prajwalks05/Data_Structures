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

void deleteBegin(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        node *temp = *head;
        *head = (*head)->next;
        printf("Deleted Element:%d\n", temp->data);
        free(temp);
    }
}

void deleteEnd(node **head)
{
    if (*head == NULL)
        return;

    node *temp = *head;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    int val = temp->data;
    printf("Element deleted at the end: %d\n", val);
    free(temp);
}

void deletePos(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 0)
    {
        deleteBegin(head);
        return;
    }
    node *temp = *head;
    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    node *prev = temp->prev;
    node *next = temp->next;
    if (prev != NULL)
    {
        prev->next = next;
    }
    if (next != NULL)
    {
        next->prev = prev;
    }

    printf("Deleted at position %d the value is: %d\n", position, temp->data);
    free(temp);
}

void display(node **head)
{
    node *temp = *head;
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
    insertbegin(&head, 40);
    insertbegin(&head, 50);
    display(&head);
    deleteBegin(&head);
    display(&head);
    deleteEnd(&head);
    display(&head);
    deletePos(&head, 1);
    display(&head);
    return 0;
}
