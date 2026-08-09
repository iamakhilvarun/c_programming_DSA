#include <stdio.h>

int main()
{
    int row, col;
    int s1[100][3];
    int s2[100][3];
    int z = 0, nz = 0;
    int arr[100][100];
    int k1 = 1;
    int sum[100][3];

    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &row, &col);

    printf("Enter elements of sparse matrix--> 1:\n");

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("Output of the first matrix:\n");
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

    s1[0][0] = row;
    s1[0][1] = col;
    s1[0][2] = nz;
    // Logic to get the triplet
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                s1[k1][0] = i;
                s1[k1][1] = j;
                s1[k1][2] = arr[i][j];
                k1++;
            }
        }
    }
    printf("Sparse matrix --> 1:\n");
    // sparse matrix representation
    for (int i = 0; i < k1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", s1[i][j]);
        }
        printf("\n");
    }

    // input ofr 2nd matrix
    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &row, &col);

    printf("Enter elements of sparse matrix--> 2:\n");

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("Output of 2nd matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    int k2 = 1;
    z = 0, nz = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
                z++;
            else
                nz++;
        }
    }

    s2[0][0] = row;
    s2[0][1] = col;
    s2[0][2] = nz;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                s2[k2][0] = i;
                s2[k2][1] = j;
                s2[k2][2] = arr[i][j];
                k2++;
            }
        }
    }
    printf("Sparse matrix --> 2:\n");
    // sparse matrix representation
    for (int i = 0; i < k2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", s2[i][j]);
        }
        printf("\n");
    }

    int s3[200][3];
    int i = 1, j = 1, k = 1;

    // Header
    s3[0][0] = s1[0][0];
    s3[0][1] = s1[0][1];

    // Merge the two sparse matrices
    while (i < k1 && j < k2)
    {
        // Same position
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1])
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2] + s2[j][2];

            i++;
            j++;
            k++;
        }
        // s1 comes first
        else if ((s1[i][0] < s2[j][0]) ||
                 (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];

            i++;
            k++;
        }
        // s2 comes first
        else
        {
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];

            j++;
            k++;
        }
    }

    // Copy remaining elements of s1
    while (i < k1)
    {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];

        i++;
        k++;
    }

    // Copy remaining elements of s2
    while (j < k2)
    {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];

        j++;
        k++;
    }

    // Header
    s3[0][2] = k - 1;

    // Print Result
    printf("\nSum of Sparse Matrices:\n");

    for (int x = 0; x < k; x++)
    {
        printf("%d\t%d\t%d\n", s3[x][0], s3[x][1], s3[x][2]);
    }

    return 0;
}