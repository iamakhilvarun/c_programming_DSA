#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *newnode;
void enqueue()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("your queue is empty");
    }
    else if (front == rear)
    {
        struct node *temp = front;
        printf("Your deleted item is: %d", temp->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = front;
        printf("Your deleted item is: %d", temp->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("your queue is empty");
    }
    else
    {
        struct node *temp = front;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

void isempty()
{
    if (front == NULL && rear == NULL)
    {
        printf("your queue is empty");
    }
    else
    {
        printf("queue is not empty!");
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
        printf("5) Exit\n");

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
            printf("\nExiting the program\n");
            return 0;

        default:
            break;
        }
    }
    return 0;
}