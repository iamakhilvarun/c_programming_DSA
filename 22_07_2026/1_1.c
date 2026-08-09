#include <stdio.h>

void compare(int *a, int *b)
{
    if (*a > *b)
    {
        printf("a is greater than b");
    }
    else if (*a < *b)
    {
        printf("b is greater than a");
    }
    else
    {
        printf("a is equal to b");
    }
}

int main()
{
    int a, b;

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    compare(&a, &b);   // Passing addresses

    return 0;
}