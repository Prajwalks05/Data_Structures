#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void insertAtBegin(node **head, int val)
{
    node *newNode = (node *)malloc(sizeof(node)); 
    newNode->data = val;                         
    newNode->next = *head;                        
    *head = newNode;                             
}

void display(node *head)
{
    node *temp = head; 
    while (temp)
    {
        printf("%d->", temp->data); 
        temp = temp->next;          
    }
    printf("NULL\n");
}

void stackAppend(node *head, int stack[], int *top)
{
    node *temp = head; 
    while (temp != NULL)
    {                                 
        stack[++(*top)] = temp->data; 
        printf("Stack element added: %d\n", stack[*top]);
        temp = temp->next;
    }
}

void cmpStack(node *head, int stack[], int *top)
{
    node *temp = head;
    while (temp != NULL && *top != -1)
    {
        if (temp->data != stack[*top])
        { 
            printf("Not a palindrome\n");
            return;
        }
        (*top)--;          
        temp = temp->next;
    }
    printf("Palindrome\n"); 
}

int main()
{
    int stack[10];     
    int top = -1;      
    node *head = NULL;


    insertAtBegin(&head, 30);
    insertAtBegin(&head, 20);
    insertAtBegin(&head, 10);
    insertAtBegin(&head, 20);
    insertAtBegin(&head, 30);
    printf("Linked List: ");
    display(head);
    stackAppend(head, stack, &top);
    cmpStack(head, stack, &top);
    return 0;
}
