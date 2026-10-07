#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;

struct node *newnode;
void insert_at_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insert()
{
    int pos;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_at_beginning();
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    struct node *temp = head;
    for (int i = 1; i <= pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insert_at_end()
{
    if (!head)
    {
        insert_at_beginning();
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("list is empty!");
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

void delete()
{
    int pos;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_at_beginning();
        return;
    }
    struct node *temp = head;
    for (int i = 1; i <= pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid position!\n");
        return;
    }
    struct node *del = temp;
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    del->prev->next = del->next;
    free(del);
}


void delete_at_end(){
    if(head==NULL){
        printf("list is empty!");
        return;
    }
    struct node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node * del=temp;
    if(del->prev!=NULL){
        del->prev->next=NULL;
    }
    else{
        head=NULL;
    }
    free(del);
}


