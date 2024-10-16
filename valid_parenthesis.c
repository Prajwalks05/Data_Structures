//Leet code problem #20;
#include <string.h>
bool isValid(char* s) {
    char opn_stk[10];
    char cls_stk[10];
    for (int i = 0; i < strlen(s); i++) 
    {
        int j=0;
        char c = s[0];
        if (c == '(' || c == '{' || c == '[')
        {
            opn_stk[j] = c;
        }
        
        if (c == ')' || c == '}' || c == ']') 
        {
            cls_stk[j] = c;
        }
        if(opn_stk[j]==cls_stk[j])
        {
            return true;   
        }
        else
        {
            return false;
        }
    }
    return 0;
}
