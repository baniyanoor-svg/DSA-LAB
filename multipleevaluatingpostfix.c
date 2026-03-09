// p3 that is multiple digits with spacing in postfix evaluation
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSTACK 100

int stack[MAXSTACK];
int top = -1;

void push(int item)
{
    if(top >= MAXSTACK - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if(top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void EvalPostfix(char postfix[])
{
    int i = 0;
    int num;

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            num = 0;

            while(isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }

            push(num);
        }

        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            int A = pop();
            int B = pop();
            int val;

            switch(postfix[i])
            {
                case '+': val = B + A; break;
                case '-': val = B - A; break;
                case '*': val = B * A; break;
                case '/': val = B / A; break;
            }

            push(val);
            i++;
        }

        else
        {
            i++; 
        }
    }

    printf("Result = %d\n", pop());
}

int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    EvalPostfix(postfix);

    return 0;
}