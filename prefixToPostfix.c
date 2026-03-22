#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

// Check operator
int isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

// Prefix to Postfix
void prefixToPostfix(char *prefix) {
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            push(op);
        }
        else if (isOperator(ch)) {
            char *op1 = pop();
            char *op2 = pop();

            char temp[MAX];
            sprintf(temp, "%s%s%c", op1, op2, ch);

            push(temp);
        }
    }

    printf("Postfix Expression: %s\n", pop());
}

int main() {
    char prefix[MAX];

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}