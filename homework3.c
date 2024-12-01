#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int det2x2(int **matrix)
{
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}
int det3x3(int **matrix)
{
    int a = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[2][0] * matrix[1][2] + matrix[0][2] * matrix[1][0] * matrix[2][1];
    int b = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[0][0] * matrix[2][1] * matrix[1][2] + matrix[0][1] * matrix[1][0] * matrix[2][2];
    return a - b;
}

int main()
{
    unsigned int N = 0;
    printf("Enter the number N:\n");
    if (scanf("%u", &N) < 1 || N > 3)
    {
        printf("error");
        return 1;
    }
  
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }
    printf("Enter the elements of the matrix (%d x %d):\n", N, N);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%d", &(matrix[y][x]));
        }
    }
    printf("The entered matrix is:\n");
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            printf("%d ", matrix[y][x]);
        }
        printf("\n");
    }

    if (N == 1)
    {
        printf("The determinant of matrix is: %d\n", matrix[0][0]);
    }
    if (N == 2)
    {
        printf("The determinant of matrix is: %d\n", det2x2(matrix));
    }
    if (N == 3)
    {
        printf("The determinant of matrix is: %d\n", det3x3(matrix));
    }

    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}
