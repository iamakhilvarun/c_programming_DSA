#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i;

    printf("Enter no.of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter info of node%d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make the list circular
    temp->next = head;

    // Display circular linked list
    printf("Clinkedlist: ");

    temp = head;

    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}