#include <stdio.h>
#include <stdlib.h>
// Todo:
// sort the list in ascending order
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

// Function for the inserting the node at the beginning
void insertAtbeginning(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    printf("insert sucessfully");
}
// Function for the inserting the node at any postion
void insert(int val, int pos)
{
    if (pos <= 1)
    {
        insertAtbeginning(val);
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid postion\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("inseted sucessfully");
}
// Delete alogorithim
// Function for the deleting the node at the beginning
void delete_beginning()
{
    if (!head)
    {
        printf("list empty");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted sucessfully");
}

// Function for the deleting the node at any postion
void delete_postion(int pos)
{
    if (!head)
    {
        return;
    }
    if (pos == 1)
    {
        delete_beginning();
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (!temp || !temp->next)
    {
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Deleted");
}

// Function for the COUNTING NODES
int count_nodes()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function for the traverse and print the nodes
void Traverse()
{
    if (!head)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    printf("Element are: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}
void search(int key)
{
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found %d", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
}
void Reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // save next node
        current->next = prev; // reverse the link
        prev = current;       // move prev forward
        current = next;       // move current forward
    }
    head = prev;
    printf("List reversed successfully");
}

int main()
{

    int choice;
    int val, pos;

    while (1)
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Delete beginning\n");
        printf("4. Delete at position\n");
        printf("5. Count nodes\n");
        printf("6. Traverse\n");
        printf("7. Reverse\n");
        printf("8. search\n");
        printf("9. Exit\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);

            insertAtbeginning(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);

            printf("Enter position: ");
            scanf("%d", &pos);
            insert(val, pos);
            break;

        case 3:
            delete_beginning();
            break;

        case 4:
            printf("Enter postion: ");
            scanf("%d", &pos);

            delete_postion(pos);
            break;

        case 5:
            printf("Number of nodes = %d\n", count_nodes());
            break;

        case 6:
            Traverse();
            break;

        case 7:
            Reverse();
            break;

        case 8:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(val);
            break;

        case 9:
            printf("Exiting the program\n");
            return 0;

        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}