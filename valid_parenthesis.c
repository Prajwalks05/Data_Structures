// Leet code problem #20;
#include <string.h>
bool isValid(char* s) {
    char opn_stk[10];
    int top = s[0];
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            opn_stk[i] = c;
            top++;
        }
        for (int j = 0; j < strlen(s); j++) {
            if (c== s[i]) {
                return true;
            }
        }
    }

    return false;
}
