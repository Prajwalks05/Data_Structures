#include <stdio.h>
#define max 20

void insert_at_front(int *front, int *rear, int queue[], int val)
{
    if ((*front == 0 && *rear == max - 1) || (*front == (*rear + 1) % max))
    {
        printf("Queue is full\n");
    }
    else if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
        queue[*front] = val; // Insert the first element
    }
    else if (*front == 0)
    {
        *front = max - 1; // Wrap around
        queue[*front] = val;
    }
    else
    {
        (*front)--;          // Move front
        queue[*front] = val; // Insert value
    }
    printf("Inserted at front: %d\n", queue[*front]);
}

int main(void)
{
    int queue[max];
    int front = -1;
    int rear = -1;

    insert_at_front(&front, &rear, queue, 10);
    return 0;
}
