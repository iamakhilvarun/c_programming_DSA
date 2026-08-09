#include <stdio.h>

void countNonZero(int arr[100][100], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0)
                count++;
        }
    }

    printf("\nNonzero elements : %d\n", count);
}

void upperTriangular(int arr[100][100], int n) {
    printf("\nUpper triangular matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void diagonalElements(int arr[100][100], int n) {
    printf("\nElements just above the main diagonal:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i][i + 1]);
    }

    printf("\nElements just below the main diagonal:\n");
    for (int i = 1; i < n; i++) {
        printf("%d ", arr[i][i - 1]);
    }
    printf("\n");
}

int main() {
    int n;
    int arr[100][100];

    printf("Enter size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    countNonZero(arr, n);
    upperTriangular(arr, n);
    diagonalElements(arr, n);

    return 0;
}