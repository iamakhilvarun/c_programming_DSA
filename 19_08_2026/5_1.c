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
void insert_end()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insertatanypos()
{
    int pos;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Enter the data:");
    scanf("%d", &newnode->data);

    if (!head)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    if (pos == 1)
    {
        insertatbeginning();
        return;
    }
    // traversing to next node
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invaild position");
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("list it empty!");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}
void delete_at_any_pos()
{
    int pos;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_at_beginning();
        return;
    }
    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
    {
        del->next->prev = temp;
    }
    free(del);
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("List it empty!");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev == NULL) // if there is only one node
    {
        head == NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }
    free(temp);
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

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertbeginning();
            break;
        case 2:
            insert();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_at_beginning();
            break;
        case 5:
            delete_at_any_pos();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            traverse();
            break;
        default:
            break;
        }
    } while (choice != 6);
}