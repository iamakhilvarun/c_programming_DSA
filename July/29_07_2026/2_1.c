#include <stdio.h>

void Insert_element(int arr[], int *n) {
    int pos, val;

    printf("Enter the position (0 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid Position!\n");
        return;
    }

    printf("Enter the new element: ");
    scanf("%d", &val);

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*n)++;

    printf("Element inserted successfully!\n");
}

void Delete_element(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter the position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid Position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully!\n");
}

void Linear_Search(int arr[], int n) {
    int key;
    int found = 0;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found!\n");
    }
}

void Traverse(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("\nArray Elements:\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr[100];
    int n, choice;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n=====================================\n");
        printf("             MAIN MENU\n");
        printf("=====================================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            Insert_element(arr, &n);
            Traverse(arr, n);
            break;

        case 2:
            Delete_element(arr, &n);
            Traverse(arr, n);
            break;

        case 3:
            Linear_Search(arr, n);
            break;

        case 4:
            Traverse(arr, n);
            break;

        case 5:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}