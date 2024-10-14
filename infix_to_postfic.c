#include <stdio.h>
#include <string.h>
#include <ctype.h>
int getPrecedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
void infix_postfix(const char *exp, char *stack, char *post)
{
    int stack_top = 0;
    int post_top = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        char c = exp[i];
        if (isalnum(c))
        {                         // If it's an operand (a-z, A-Z, 0-9)
            post[post_top++] = c; // Add to postfix
        }
        else if (c == '(')
        {
            stack[stack_top++] = c; // Push '(' onto the stack
        }
        else if (c == ')')
        {
            while (stack_top > 0 && stack[stack_top - 1] != '(')
            {
                post[post_top++] = stack[--stack_top]; // Pop to postfix
            }
            stack_top--; // Pop the '('
        }
        else
        { 
            while (stack_top > 0 && getPrecedence(stack[stack_top - 1]) >= getPrecedence(c))
            {
                post[post_top++] = stack[--stack_top]; // Pop higher or equal precedence
            }
            stack[stack_top++] = c; // Push current operator
        }
    }
    // Pop all operators from the stack
    while (stack_top > 0)
    {
        post[post_top++] = stack[--stack_top];
    }
    post[post_top] = '\0'; // Null terminate the postfix expression
}
int main()
{
    char stack[20];
    char post[20];
    char exp[] = "(a+b)*(c/d)";
    infix_postfix(exp, stack, post);
    printf("Postfix expression: %s\n", post); // Output the postfix expression
    return 0;
}
