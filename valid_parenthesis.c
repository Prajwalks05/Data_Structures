// Leet code problem #20;
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char opn_stk[10];
    int top = 0;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            opn_stk[top++] = c; 
        } 
        else {
            if (top == 0) {
                return false; 
            }
            char last = opn_stk[top - 1]; 
            if ((c == ')' && last == '(') || 
                (c == '}' && last == '{') || 
                (c == ']' && last == '[')) {
                top--;
            } else {
                return false;
            }
        }
    }

    return top == 0; // If stack is empty, all brackets matched
}

