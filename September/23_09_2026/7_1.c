#include <stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);

    if (rear == N - 1)
    {
        printf("overflow!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("underflow!");
    }
    else if (front == rear)
    {
        printf("your deleted item is: %d", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("your deleted item is: %d", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Your queue is empty!");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d", queue[i]);
        }
    }
}

void isempty()
{
    if (front == -1 && rear == -1)
    {
        printf("your queue is empty!");
    }
    else
    {
        printf("You queue is not empty!");
    }
}

void isfull()
{
    if (rear == N - 1)
    {
        printf("you queue is full!");
    }
    else
    {
        printf("your queue is not full!");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n-----------Menu-----------\n");
        printf("1) enqueue\n");
        printf("2) dequeue\n");
        printf("3) display\n");
        printf("4) isempty\n");
        printf("5) isfull\n");
        printf("6) Exit\n");
        
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            isempty();
            break;
        case 5:
            isfull();
            break;
        case 6:
            printf("\nExiting the program\n");
            return 0;

        default:
            break;
        }
    }
    return 0;
}