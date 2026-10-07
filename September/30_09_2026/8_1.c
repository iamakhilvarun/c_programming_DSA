#include <stdio.h>

#define MAX 5

/* ================= INPUT RESTRICTED DEQUE ================= */

int irDeque[MAX];
int irFront = -1, irRear = -1;

int irIsEmpty()
{
    return irFront == -1;
}

int irIsFull()
{
    return irRear == MAX - 1;
}

/* Enqueue only at rear */
void irEnqueue(int value)
{
    if (irIsFull())
    {
        printf("Input Restricted Deque is FULL!\n");
        return;
    }

    if (irFront == -1)
        irFront = 0;

    irDeque[++irRear] = value;
    printf("%d inserted at rear.\n", value);
}

/* Dequeue from front */
void irDequeueFront()
{
    if (irIsEmpty())
    {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("%d deleted from front.\n", irDeque[irFront]);

    if (irFront == irRear)
        irFront = irRear = -1;
    else
        irFront++;
}

/* Dequeue from rear */
void irDequeueRear()
{
    if (irIsEmpty())
    {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("%d deleted from rear.\n", irDeque[irRear]);

    if (irFront == irRear)
        irFront = irRear = -1;
    else
        irRear--;
}

/* Peek */
void irPeek()
{
    if (irIsEmpty())
    {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Front element: %d\n", irDeque[irFront]);
    printf("Rear element : %d\n", irDeque[irRear]);
}

/* ================= OUTPUT RESTRICTED DEQUE ================= */

int orDeque[MAX];
int orFront = -1, orRear = -1;

int orIsEmpty()
{
    return orFront == -1;
}

int orIsFull()
{
    return orRear == MAX - 1;
}

/* Enqueue at rear */
void orEnqueueRear(int value)
{
    if (orIsFull())
    {
        printf("Output Restricted Deque is FULL!\n");
        return;
    }

    if (orFront == -1)
        orFront = 0;

    orDeque[++orRear] = value;
    printf("%d inserted at rear.\n", value);
}

/* Enqueue at front */
void orEnqueueFront(int value)
{
    if (orIsFull())
    {
        printf("Deque is FULL!\n");
        return;
    }

    if (orFront == -1)
    {
        orFront = orRear = 0;
        orDeque[orFront] = value;
    }
    else if (orFront > 0)
    {
        orDeque[--orFront] = value;
    }
    else
    {
        printf("Cannot insert at front!\n");
        return;
    }

    printf("%d inserted at front.\n", value);
}

/* Dequeue only from front */
void orDequeue()
{
    if (orIsEmpty())
    {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("%d deleted from front.\n", orDeque[orFront]);

    if (orFront == orRear)
        orFront = orRear = -1;
    else
        orFront++;
}

/* Peek */
void orPeek()
{
    if (orIsEmpty())
    {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Front element: %d\n", orDeque[orFront]);
    printf("Rear element : %d\n", orDeque[orRear]);
}

/* ================= MAIN MENU ================= */

int main()
{
    int mainChoice, choice, value;

    while (1)
    {
        printf("\n========== DEQUE MENU ==========\n");
        printf("1. Input Restricted Deque\n");
        printf("2. Output Restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        if (mainChoice == 3)
        {
            printf("Program terminated.\n");
            break;
        }

        /* INPUT RESTRICTED DEQUE */
        if (mainChoice == 1)
        {

            while (1)
            {
                printf("\n--- INPUT RESTRICTED DEQUE ---\n");
                printf("1. Enqueue (Rear)\n");
                printf("2. Dequeue (Front)\n");
                printf("3. Dequeue (Rear)\n");
                printf("4. Peek\n");
                printf("5. IsEmpty\n");
                printf("6. IsFull\n");
                printf("7. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch (choice)
                {

                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    irEnqueue(value);
                    break;

                case 2:
                    irDequeueFront();
                    break;

                case 3:
                    irDequeueRear();
                    break;

                case 4:
                    irPeek();
                    break;

                case 5:
                    printf(irIsEmpty() ? "Deque is EMPTY.\n" : "Deque is NOT EMPTY.\n");
                    break;

                case 6:
                    printf(irIsFull() ? "Deque is FULL.\n" : "Deque is NOT FULL.\n");
                    break;

                case 7:
                    goto main_menu;

                default:
                    printf("Invalid choice!\n");
                }
            }
        }

        /* OUTPUT RESTRICTED DEQUE */
        else if (mainChoice == 2)
        {

            while (1)
            {
                printf("\n--- OUTPUT RESTRICTED DEQUE ---\n");
                printf("1. Enqueue (Rear)\n");
                printf("2. Enqueue (Front)\n");
                printf("3. Dequeue (Front)\n");
                printf("4. Peek\n");
                printf("5. IsEmpty\n");
                printf("6. IsFull\n");
                printf("7. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch (choice)
                {

                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    orEnqueueRear(value);
                    break;

                case 2:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    orEnqueueFront(value);
                    break;

                case 3:
                    orDequeue();
                    break;

                case 4:
                    orPeek();
                    break;

                case 5:
                    printf(orIsEmpty() ? "Deque is EMPTY.\n" : "Deque is NOT EMPTY.\n");
                    break;

                case 6:
                    printf(orIsFull() ? "Deque is FULL.\n" : "Deque is NOT FULL.\n");
                    break;

                case 7:
                    goto main_menu;

                default:
                    printf("Invalid choice!\n");
                }
            }
        }

        else
        {
            printf("Invalid choice!\n");
        }

    main_menu:;
    }

    return 0;
}