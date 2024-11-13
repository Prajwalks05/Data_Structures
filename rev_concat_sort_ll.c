#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

node *insertBegin(node *head, int val)
{
    node *newnode = createnode(val);
    newnode->next = head;
    head = newnode;
    return newnode;
}

node *concat(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void sort(node *head)
{
    if (head == NULL)
        return;
    node *current, *temp;
    int t;
    for (current = head; current != NULL; current = current->next)
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (temp->data > temp->next->data)
            {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
        }
    }
}

node *reverse(node *head)
{
    node *prev = NULL, *temp = head, *next;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    list1 = insertBegin(list1, 3);
    list1 = insertBegin(list1, 2);
    list1 = insertBegin(list1, 1);
    list2 = insertBegin(list2, 6);
    list2 = insertBegin(list2, 5);
    list2 = insertBegin(list2, 4);

     printf("list1:\t");
    display(list1);
    printf("list2:\t");
    display(list2);

    printf("reversing lists\n");
    list1 = reverse(list1);  // Update the list1 pointer
    printf("reversed list1:\t");
    display(list1);

    list2 = reverse(list2);  // Update the list2 pointer
    printf("reversed list2:\t");
    display(list2);

    printf("after concatenation:\n");
    list1 = concat(list1, list2);  // Update the list1 pointer
    display(list1);
}
