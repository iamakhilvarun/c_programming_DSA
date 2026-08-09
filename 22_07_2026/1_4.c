#include <stdio.h>

struct Complex
{
    int real;
    int imag;
};

// Function to take input
void inputComplex(struct Complex *c)
{
    printf("Enter real part: ");
    scanf("%d", &c->real);

    printf("Enter imaginary part: ");
    scanf("%d", &c->imag);
}

// Function to display a complex number
void displayComplex(struct Complex c)
{
    if (c.imag >= 0)
        printf("%d + %di\n", c.real, c.imag);
    else
        printf("%d - %di\n", c.real, -c.imag);
}

// Call by Value
struct Complex addition(struct Complex c1, struct Complex c2)
{
    struct Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

// Call by Address
void multiplication(struct Complex *c1, struct Complex *c2, struct Complex *result)
{
    result->real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result->imag = (c1->real * c2->imag) + (c1->imag * c2->real);
}

int main()
{
    int choice;
    struct Complex c1, c2, result;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Addition (Call by Value)\n");
        printf("2. Multiplication (Call by Address)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nFirst Complex Number\n");
            inputComplex(&c1);

            printf("\nSecond Complex Number\n");
            inputComplex(&c2);

            result = addition(c1, c2);

            printf("\nResult: ");
            displayComplex(result);
            break;

        case 2:
            printf("\nFirst Complex Number\n");
            inputComplex(&c1);

            printf("\nSecond Complex Number\n");
            inputComplex(&c2);

            multiplication(&c1, &c2, &result);

            printf("\nResult: ");
            displayComplex(result);
            break;

        case 3:
            printf("\nExiting Program...\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}