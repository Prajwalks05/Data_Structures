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
    insertAtbeggining(&head, 50);
    display(&head);
    printf("\nDelete at begin");
    deleteAtFront(&head);
    display(&head);
    printf("\nDelete at end\n");
    deleteAtEnd(&head);
    display(&head);
    printf("\nDelete at specific position\n");
    deleteAtPos(&head, 1);
    display(&head);
    return 0;
}
