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

void insertAfter(node **head, int prev, int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;

    node *temp = *head;
    while (temp != NULL && temp->data != prev)
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
    printf("\nDisplaying...\n");
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
    printf("\nInsert after");
    insertAfter(&head, 20, 25);
    display(&head);
    printf("delete at begin");
    deleteAtFront(&head);
    display(&head);
    printf("delete at end");
    deleteAtEnd(&head);
    display(&head);
    return 0;
}
