#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void insertAtbeggining(node **head, int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

void insertAtend(node **head, int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
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
}

void insertAtPos(node **head, int position, int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;

    node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display(node **head)
{
    node *temp = *head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtFront(int **head)
{
    if (*head == NULL)
    {
        free(head);
        return;
    }
    node *temp = *head;
    *head = temp->next;
    free(temp);
}
void deleteAtEnd(int **head)
{
    node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPos(int **head, int position)
{
    node *temp = *head;
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
int main(void)
{
    node *head = NULL;
    printf("Insert at begin");
    insertAtbeggining(&head, 10);
    insertAtbeggining(&head, 20);
    insertAtbeggining(&head, 30);
    insertAtbeggining(&head, 40);
    display(&head);
    printf("\nInsert at end");
    insertAtend(&head, 50);
    insertAtend(&head, 60);
    display(&head);
    printf("\nInsert at position");
    insertAtPos(&head, 3, 25);
    display(&head);
    printf("\nDelete at begin");
    deleteAtFront(&head);
    display(&head);
    printf("\nDelete at end");
    deleteAtEnd(&head);
    display(&head);
    printf("\nDelete at specific position");
    deleteAtPos(&head, 4);
    display(&head);
    return 0;
}
