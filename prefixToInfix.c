#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Push function
void push(char *str) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], str);
}

// Pop function
char* pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Check if operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Prefix to Infix conversion
void prefixToInfix(char *prefix) {
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If operand
        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            push(op);
        }
        // If operator
        else if (isOperator(ch)) {
            char *op1 = pop();
            char *op2 = pop();

            char temp[MAX];
            sprintf(temp, "(%s%c%s)", op1, ch, op2);

            push(temp);
        }
    }

    printf("Infix Expression: %s\n", pop());
}

// Main function
int main() {
    char prefix[MAX];

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix);

    return 0;
}