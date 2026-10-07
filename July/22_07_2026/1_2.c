#include <stdio.h>
#include <stdlib.h>

void prime(int n, int arr[]) {
    int sum = 0;
    int isprime;

    // Check each number
    for (int i = 0; i < n; i++) {

        if (arr[i] < 2)
            continue;

        isprime = 1;

        for (int j = 2; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                isprime = 0;
                break;
            }
        }

        if (isprime)
            sum += arr[i];
    }

    printf("The sum of prime numbers is: %d\n", sum);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    prime(n, arr);

    // Free allocated memory
    free(arr);

    return 0;
}