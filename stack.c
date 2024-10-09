#include<stdio.h>

int main() {
    int n = 5;
    int stack[5] = {1, 2, 3, 4, 5,6};
    int top = -1;
    int end = n - 1;
    printf("Push operation\n");
    for (int i = 0; i <= end; i++) {
        printf("%d\n", stack[i]);
        top = i;
        if (top == end) {
            printf("Stack is full\n");
        }
    }
    printf("Pop operation\n");
    for (int i = top; i >= 0; i--) {
        printf("%d \n", stack[i]);
    }
    if(end==top)
    {
        printf("stack is empty");
    }
    printf("\n");
    return 0;

}
