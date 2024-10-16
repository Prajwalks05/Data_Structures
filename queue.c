#include <stdio.h>
#define max 10

void enqueue(int *front, int *rear, int queue[], int val)
{
    if (*rear == (max - 1))
    {
        printf("Queue is full\n");
        return;
    }
    else if (*front == -1 || *rear == -1)
    {
        *front = *rear = 0;
    }
    else
    {
        (*rear)++; // Increment rear properly
    }

    queue[*rear] = val;
    printf("%d\n", queue[*rear]);

    // This check is not necessary after enqueue
}

void dequeue(int *front, int *rear, int queue[])
{
    if ((*front) == -1 || *front > *rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int val = queue[*front];
        printf("%d\n", val);
        (*front)++; // Increment front properly

        // Reset if the queue is now empty
        if (*front > *rear)
        {
            *front = *rear = -1;
        }
    }
}

int display(int front, int rear, int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
    return 0; // Optional return
}

int main(void)
{
    int front = -1;
    int rear = -1;
    int queue[max];

    printf("Enqueueing:\n");
    enqueue(&front, &rear, queue, 10);
    enqueue(&front, &rear, queue, 20);
    enqueue(&front, &rear, queue, 30);
    enqueue(&front, &rear, queue, 40);
    enqueue(&front, &rear, queue, 50);

    printf("Dequeueing:\n");
    dequeue(&front, &rear, queue);
    dequeue(&front, &rear, queue);
    dequeue(&front, &rear, queue);
    dequeue(&front, &rear, queue);

    display(front, rear, queue);

    return 0;
}
