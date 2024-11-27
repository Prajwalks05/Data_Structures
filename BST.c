#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;

node *newnode(int val)
{
    node *temp = (node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

node *insertnode(node *node, int val)
{
    if (node == NULL)
    {
        return newnode(val);
    }
    else if (val < node->data)
    {
        node->left = insertnode(node->left, val);
    }
    else
    {
        node->right = insertnode(node->right, val);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}
void postorder(node *root)
{ 
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

void main()
{
    node *root = NULL;
    root = insertnode(root, 100);
    insertnode(root, 20);
    insertnode(root, 65);
    insertnode(root, 40);
    insertnode(root, 5);
    insertnode(root, 60);
    insertnode(root, 95);
    insertnode(root, 35);
    insertnode(root, 20);
    printf("\npreorder Traversal\n");
    preorder(root);
    printf("\ninorder Traversal\n");
    inorder(root);
    printf("\npostorder Traversal\n");
    postorder(root);
}
