#include<stdio.h>
#define max 10
void enqueue(int *front,int *rear,int queue[],int val)
{
    if(*rear==(max-1))
    {
        printf("Queue is full");
        return;
    }
    else if(*front==-1 || *rear==-1)
    {
        *front=*rear=0;
    }
    (*rear)++;
    queue[*rear]=val;
}
void dequeue(int *front,int *rear,int queue[])
{
    if(*front==-1 || *front>*rear)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
       int val=queue[*front];
    (*front)++;
    }
}
void display(int *front,int *rear,int queue[])
{
   if(*front==-1|| *front>*rear)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
    printf("%d",front);
    printf("%d",rear);
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
    }
}
void main()
{
    int queue[max];
    int front=queue[-1];
    int rear=queue[-1];
printf("enqueue:\n");
    enqueue(&front,&rear,queue,10);
    enqueue(&front,&rear,queue,20);
     enqueue(&front,&rear,queue,30);
    enqueue(&front,&rear,queue,40);
    printf("display\n");
    display(front,rear,queue);
    printf("dequeue\n");
    dequeue(front,rear,queue);
    display(front,rear,queue);
}
