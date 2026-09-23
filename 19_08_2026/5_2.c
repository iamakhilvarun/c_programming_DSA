#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (top == NULL)
    {
        printf("stack is empty!");
        return;
    }

    struct node *temp = top;

    top = top->next;

    free(temp);
}

void traverse()
{
    if (top == NULL)
    {
        printf("The stack is empty!");
        return;
    }
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("Null");
}

void isempty()
{
    if (top == NULL)
    {
        printf("The stack is empty!");
    }
    else
    {
        printf("stack is not empty!");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n-------Stack MENU-------\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.traverse\n");
        printf("4.isempty\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            isempty();
            break;
        case 5:
            printf("\nExiting....");
            exit(0);
        default:
            printf("Invalid choice!");
            break;
        }
    }

    return 0;
}