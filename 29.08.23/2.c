// Write program to convert sparse matrix into row and column triplet. 

#include <stdio.h>
#include <stdlib.h>

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


    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            printf("%d ", matrix[p][q]);
        }
        printf("\n");
    }

    int count = 0;

    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (matrix[p][q] != 0)
            {
                count++;
            }
        }
    }

        int sparseMatrix[count][3];

    int k = 0;

    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (matrix[p][q] != 0)
            {
                sparseMatrix[k][0] = p;
                sparseMatrix[k][1] = q;
                sparseMatrix[k][2] = matrix[p][q];
                k++;
            }
        }
    }

    for (int p = 0; p < count; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            printf("%d ", sparseMatrix[p][q]);
        }
        printf("\n");
    }
    
    return 0;
}