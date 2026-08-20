#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void insertbeginning()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}
void insert()
{   int pos;
    struct node *temp = head;
    struct node *prevnode = NULL;

    if (head == NULL)
    {
        insertbeginning();
        return;
    }
    printf("\nEnter the postion: ");
    scanf("%d", &pos);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
        return;
    }

    int i = 1;
    temp = head; //travrese
    while (temp != NULL && i < pos)
    {
        prevnode = temp;
        temp = temp->next;
        i++;
    }

    newnode->next = temp;
    newnode->prev = prevnode;

    prevnode->next = newnode;
    if (temp != NULL)
    {
        temp->prev = newnode;
    }
}

void traverse()
{
    if (!head)
    {
        printf("Empty list!");
        return;
    }
    struct node *temp = head;
    printf("Elements of the list: ");
    while (temp != NULL)
    {
        printf("%d->\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        printf("1) Insertatbeginning\n");
        printf("2) Insert\n");
        printf("3) Deleteatbeginning\n");
        printf("4) Delete\n");
        printf("5) Traverse\n");
        printf("6) Exit the program.....\n");
        
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            insertbeginning();
            break;
        case 2:
            insert();
            break;
        case 3:
        traverse();
        break;
        default:
            break;
        }
    }
        while (choice!=6);
}