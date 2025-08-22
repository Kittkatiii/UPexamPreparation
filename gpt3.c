#include <stdio.h>
#include <stdlib.h>

void generateMatrix(int n, int m)
{
    int** matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(int));
    }

    int number = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = number++;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int weight(int n, int m, int i, int j)
{
    int** matrix = malloc(n * sizeof(int*));
    for (int k = 0; k < n; k++)
    {
        matrix[k] = malloc(m * sizeof(int));
    }

    int number = 1;

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            matrix[k][l] = number++;
        }
    }

    int sum = matrix[i][j];

    // Top-left diagonal
    int x = i - 1, y = j - 1;
    while (x >= 0 && y >= 0)
    {
        sum += matrix[x][y];
        x--; y--;
    }

    // Top-right diagonal
    x = i - 1; y = j + 1;
    while (x >= 0 && y < m)
    {
        sum += matrix[x][y];
        x--; y++;
    }

    // Bottom-left diagonal
    x = i + 1; y = j - 1;
    while (x < n && y >= 0)
    {
        sum += matrix[x][y];
        x++; y--;
    }

    // Bottom-right diagonal
    x = i + 1; y = j + 1;
    while (x < n && y < m)
    {
        sum += matrix[x][y];
        x++; y++;
    }

    for (int k = 0; k < n; k++)
    {
        free(matrix[k]);
    }
    free(matrix);

    return sum;
}

void generateWeightedMatrix(n, m)
{
    int** matrix = malloc(n * sizeof(int*));
    for (int k = 0; k < n; k++)
    {
        matrix[k] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            matrix[i][j] = weight(n, m, i, j);
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }

    for (int p = 0; p < n;p++)
    {
        free(matrix[p]);
    }
    free(matrix);

}

void generateDeleteRowsWmatrix(int n, int m, int W)
{
    int* keepRow = malloc(n * sizeof(int));

    int keptRows = 0;
    int yes = 0;
    int hasW = 0;

    for (int i = 0; i < n;i++)
    {
        hasW = 0;
        for (int j = 0; j < m;j++)
        {
            if (weight(n, m, i, j) == W)
            {
                hasW = 1;
                break;
            }
        }

        keepRow[i] = !hasW;
        if (!hasW) keptRows++;
        
    }

    int** newMatrix = malloc(keptRows * sizeof(int*));
    int rowIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (keepRow[i])
        {
            newMatrix[rowIdx] = malloc(m * sizeof(int));
            for (int j = 0; j < m; j++)
            {
                newMatrix[rowIdx][j] = weight(n, m, i, j);
            }
            rowIdx++;
        }
    }

    for (int i = 0; i < keptRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", newMatrix[i][j]);
        }
        printf("\n\n");
    }

    for (int i = 0; i < keptRows; i++)
    {
        free(newMatrix[i]);
    }
    free(newMatrix);
    free(keepRow);
}



//int main()
//{
//    int n, m, i, j, W;
//
//    printf("Enter the size of the matrix n and m, and weight to remove W:");
//    scanf_s("%d %d %d", &n, &m, &W);
//
//    if (n <= 0 || m <= 0)
//    {
//        printf("Matrix size must be positive.\n");
//        return 0;
//    }
//
//    printf("Here's the matrix:\n");
//    generateMatrix(n, m);
//
//    printf("Here's the weighted matrix:\n");
//    generateWeightedMatrix(n, m);
//
//    printf("Here's the weighted matrix without rows containing %d:\n", W);
//    generateDeleteRowsWmatrix(n, m, W);
//
//    return 0;
//}
