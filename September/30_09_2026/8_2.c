#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

/* Enqueue */
void enqueue(int data, int priority) {
    struct node *newNode;
    struct node *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    /* If queue is empty or new node has higher priority */
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    }
    else {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element %d inserted with priority %d.\n",
           data, priority);
}

/* Dequeue */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Priority Queue is EMPTY!\n");
        return;
    }

    temp = front;

    printf("Element %d with priority %d deleted.\n",
           temp->data, temp->priority);

    front = front->next;

    free(temp);
}

/* Traverse */
void traverse() {
    struct node *temp;

    if (front == NULL) {
        printf("Priority Queue is EMPTY!\n");
        return;
    }

    temp = front;

    printf("\nPriority Queue:\n");
    printf("Data\tPriority\n");
    printf("----------------\n");

    while (temp != NULL) {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

/* Main */
int main() {
    int choice;
    int data, priority;

    while (1) {
        printf("\n========== PRIORITY QUEUE ==========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter priority: ");
                scanf("%d", &priority);

                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}