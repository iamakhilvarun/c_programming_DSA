#include <stdio.h>

int main()
{

    int row, col;
    int arr[100][100];
    int sparse[100][3];
    int Transpose[100][3];
    int k=1;

    printf("Enter the no. of rows and colunms: ");
    scanf("%d %d", &row, &col);
    //input of normal matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the element: ");
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Output:\n");
    // output of normal matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Header
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    sparse[0][2]=k-1;

    printf("\nsparse matrix:\n");
        for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }

    Transpose[0][0] = sparse[0][1];   // columns become rows
    Transpose[0][1] = sparse[0][0];   // rows become columns
    Transpose[0][2] = sparse[0][2];   // non-zero elements stay the same

    int t=1;
    for (int c = 0; c < col; c++)
    {
        for (int i = 1; i < k; i++)
        {
            if (sparse[i][1] == c)
            {
                Transpose[t][0] = sparse[i][1];
                Transpose[t][1] = sparse[i][0];
                Transpose[t][2] = sparse[i][2];
                t++;
            }
        }
    }
        printf("\nTranspose matrix:\n");
        for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", Transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}