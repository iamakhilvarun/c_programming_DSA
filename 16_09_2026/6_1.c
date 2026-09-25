#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

void push()
{
    if (top == N - 1)
    {
        printf("overflow!");
        return;
    }

    int x;
    printf("Enter the element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow condition!");
        return;
    }
    int item;
    item = stack[top];
    top--;
    printf("popped item: %d ", item);
}

void traverse()
{
    if (top == -1)
    {
        printf("underflow!");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("underflow");
        return;
    }

    printf("\tpeek:%d ", stack[top]);
}

void isempty()
{
    if (top == -1)
    {
        printf("stack is empty!");
        return;
    }
    else{
        printf("stack is not empty!");
        return;
    }
}

void isfull()
{
    if (top == N-1)
    {
        printf("stack is full!");
        return;
    }
    else{
        printf("stack is not full!");
        return;
    }
}


int main(){
    push();
    push();
    push();
    push();
    push();
    push();
    pop();
    peek();
    traverse();
    pop();
    traverse();
    isempty();
    isfull();

    return 0;
}