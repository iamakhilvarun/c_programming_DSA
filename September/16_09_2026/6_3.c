#include <stdio.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    return 0;
}


void infixToPostfix(char infix[])
{
    char postfix[100];
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            pop();   // Remove '('
        }

        // Operator
        else
        {
            while (top != -1 &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}