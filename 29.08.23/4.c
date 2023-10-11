// WAP to display the upper and lower triangular matrix of a 2D array.

#include <stdio.h>

int main() {

    int m, n;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix[m][n];

    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            printf("Enter the element at (%d, %d): ", p, q);
            scanf("%d", &matrix[p][q]);
        }
    }

    printf("The upper triangular matrix is: \n");

    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (p <= q)
            {
                printf("%d ", matrix[p][q]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }


    printf("The lower triangular matrix is: \n");

    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (p >= q)
            {
                printf("%d ", matrix[p][q]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}