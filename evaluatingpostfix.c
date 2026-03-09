/*. 2.EVALUATING POSTFIX Algorithm :
1.Initialize stack.
 2. Scan postfix expression from left to right.
 3. If operand → push to stack.
4. If operator:
  Pop two operands.
Perform operation.
Push result.
Repeat until expression ends.
5.Final result = pop from stack.
     */

#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

char stack[MAXSTACK];
int top = -1;

void push(int item)
{
    if (top >= MAXSTACK - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = item;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow \n");
        return -1;
    }

    return stack[top--];
}
void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int A, B, val;
    for (int i = 0; postfix[i] != '0'; i++)
    {

        ch = postfix[i];
        if (isdigit(ch))
        {

            push(ch - '0');
        }
        else if (ch == '+' 
            || ch == '-' || ch == '*' || ch == '/')
        {

            A = pop();
            B = pop();
            switch (ch)
            {

            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            }
            push(val);
        }
    }

    printf("Result = %d\n", pop());
}

int main()
{
    char postfix[POSTFIXSIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    EvalPostfix(postfix);

    return 0;
}
