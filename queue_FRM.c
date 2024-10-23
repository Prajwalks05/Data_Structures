#include<stdio.h>
#define max 100
void pushFront(int *front, int *rear, int queue[], int val)
{
    if ((*rear + 1) % max == *front)
    {
        printf("Queue is full\n");
        return;
    }
    if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
    }
    else if ((*rear) == max - 1 && (*front) != 0)
    {
        *rear = 0;
    }
    else
    {
        (*rear)++;
    }
    queue[*rear] = val;
    printf("pushFront:\t%d\n", queue[*rear]);
}


void pushRear(int *front, int *rear, int queue[], int val)
{
    if ((*rear + 1) % max == *front)
    {
        printf("Queue is full\n");
        return;
    }
    if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
    }
    else if ((*front) == max - 1)
    {
        *front = 0;
    }
    else
    {
        (*front)++;
    }
    queue[*front] = val;
    printf("pushRear:\t%d\n", queue[*front]);
}
void popRear(int *front, int *rear, int queue[])
{
    if (*front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    int val = queue[*front];
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else if (*front == (max - 1))
    {
        *front = 0;
    }
    else
    {
        (*front)++;
    }
    printf("PopRear:\t%d\n", val);
}



void display(int *front, int *rear, int queue[])
{
    if (*front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = *front;i<=*rear; i++)
    {
        printf("%d\n", queue[i]);
        if (i == *rear)
            break;
    }
}

void main()
{
int front=-1;
int rear=-1;
int queue[max];
pushFront(&front,&rear,queue,10);
pushFront(&front,&rear,queue,20);
pushFront(&front,&rear,queue,30);
pushRear(&front,&rear,queue,40);
popRear(&front,&rear,queue);
printf("Displaying..\n");
display(&front,&rear,queue);

}
