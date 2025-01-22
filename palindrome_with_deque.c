#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome using a deque
bool isPalindrome(char *str) {
    int len = strlen(str);
    char *deque = (char *)malloc(len * sizeof(char)); // Allocate memory for deque
    int front = 0, rear = -1;

    // Push characters into the deque
    for (int i = 0; i < len; i++) {
        deque[++rear] = str[i]; // Insert at rear
    }

    // Compare characters from front and rear
    while (front < rear) {
        if (deque[front++] != deque[rear--]) {
            free(deque); // Free allocated memory
            return false; // Not a palindrome
        }
    }

    free(deque); // Free allocated memory
    return true; // It's a palindrome
}

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to lowercase to handle case-insensitivity
    toLowercase(str);

    if (isPalindrome(str)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    return 0;
}
