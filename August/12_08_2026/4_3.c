#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coefficient;
    int power;
    struct node *next;
};


// Insert node in descending power order
void insert(struct node **head, int coefficient, int power)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->coefficient = coefficient;
    newnode->power = power;
    newnode->next = NULL;


    // Insert at beginning
    if(*head == NULL || (*head)->power < power)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }


    struct node *temp = *head;


    while(temp->next != NULL && temp->next->power > power)
    {
        temp = temp->next;
    }


    newnode->next = temp->next;
    temp->next = newnode;
}



// Display polynomial
void display(struct node *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }


    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%dx^%d", temp->coefficient, temp->power);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}



// Add two polynomials
void addPolynomial(struct node *poly1, struct node *poly2, struct node **sum)
{

    while(poly1 != NULL && poly2 != NULL)
    {

        if(poly1->power == poly2->power)
        {
            insert(sum,
                   poly1->coefficient + poly2->coefficient,
                   poly1->power);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }


        else if(poly1->power > poly2->power)
        {
            insert(sum,
                   poly1->coefficient,
                   poly1->power);

            poly1 = poly1->next;
        }


        else
        {
            insert(sum,
                   poly2->coefficient,
                   poly2->power);

            poly2 = poly2->next;
        }
    }



    while(poly1 != NULL)
    {
        insert(sum,
               poly1->coefficient,
               poly1->power);

        poly1 = poly1->next;
    }



    while(poly2 != NULL)
    {
        insert(sum,
               poly2->coefficient,
               poly2->power);

        poly2 = poly2->next;
    }
}



int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *sum = NULL;


    int degree;
    int coefficient;



    // Polynomial 1
    printf("Enter maximum degree of Polynomial 1: ");
    scanf("%d",&degree);


    for(int i = 0; i <= degree; i++)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d",&coefficient);


        if(coefficient != 0)
        {
            insert(&poly1, coefficient, i);
        }
    }



    // Polynomial 2
    printf("\nEnter maximum degree of Polynomial 2: ");
    scanf("%d",&degree);


    for(int i = 0; i <= degree; i++)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d",&coefficient);


        if(coefficient != 0)
        {
            insert(&poly2, coefficient, i);
        }
    }



    printf("\nPolynomial 1: ");
    display(poly1);


    printf("Polynomial 2: ");
    display(poly2);



    addPolynomial(poly1, poly2, &sum);



    printf("Sum: ");
    display(sum);



    return 0;
}