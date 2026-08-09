#include <stdio.h>

int main()
{
    int row, col;
    int s[100][3];
    int z = 0, nz = 0;
    int arr[100][100];
    int k = 1;

    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &row, &col);

    printf("Enter elements of sparse matrix:\n");

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("Output:\n");
    //Output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    //Finding zero and non-zero
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                z++;
            }
            else
            {
                nz++;
            }
        }
    }
    if (z > nz)
        printf("\nIt is a sparse matrix.\n");
    else
        printf("\nIt is not a sparse matrix.\n");

        s[0][0] = row;
        s[0][1] = col;
        s[0][2] = nz;
    // Logic to get the triplet
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = arr[i][j];
                k++;
            }
        }
    }
    printf("Sparse matrix:\n");
    // sparse matrix representation
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
}