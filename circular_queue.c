#include <stdio.h>
#define max 10

void enqueue(int *front, int *rear, int queue[], int val)
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
    printf("%d\n", queue[*rear]);
}

void dequeue(int *front, int *rear, int queue[])
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
    printf("%d\n", val);
}
void display(int *front, int *rear, int queue[])
{
    if (*front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = *front;; i = (i + 1) % max)
    {
        printf("%d\n", queue[i]);
        if (i == *rear)
            break;
    }
}

int main(void)
{
    int front = -1;
    int rear = -1;
    int queue[max];

    printf("Enqueueing\n");
    enqueue(&front, &rear, queue, 10);
    enqueue(&front, &rear, queue, 20);
    enqueue(&front, &rear, queue, 30);
    enqueue(&front, &rear, queue, 40);
    enqueue(&front, &rear, queue, 50);

    printf("Dequeue\n");
    dequeue(&front, &rear, queue);
    dequeue(&front, &rear, queue);

    printf("Queue elements:\n");
    display(&front, &rear, queue);

    return 0;
}
