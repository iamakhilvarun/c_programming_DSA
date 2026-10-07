#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int value;
    struct node *next;
};

int main() {
    struct node *header, *newnode, *temp;
    int rows, cols;
    int value, count = 0;

    header = (struct node *)malloc(sizeof(struct node));

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    header->row = rows;
    header->col = cols;
    header->value = 0;
    header->next = NULL;

    temp = header;

    printf("Enter elements of sparse matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            scanf("%d", &value);

            if (value != 0) {
                newnode = (struct node *)malloc(sizeof(struct node));

                newnode->row = i;
                newnode->col = j;
                newnode->value = value;
                newnode->next = NULL;

                temp->next = newnode;
                temp = newnode;

                count++;
            }
        }
    }

    // Store number of non-zero elements in header
    header->value = count;

    printf("\nsparse matrix in 3-tuple format\n");

    // Display header node
    printf("%d\t%d\t%d\n", header->row, header->col, header->value);

    // Display remaining nodes
    temp = header->next;

    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }

    return 0;
}