#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push function
void push(char ch)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    top++;
    stack[top] = ch;
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("Expression is Invalid\n");
        exit(1);
    }

    top--;
}

int main()
{
    char exp[SIZE];
    int i;

    printf("Enter the expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            pop();
        }
    }

    if (top == -1)
        printf("Expression is Valid\n");
    else
        printf("Expression is Invalid\n");

    return 0;
}