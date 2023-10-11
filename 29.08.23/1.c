// Write program for polynomial addition and multiplication.

#include <stdio.h>
#include <stdlib.h>


struct Polynomial
{
    int highest_degree;
    int* coefficients;
};


int main() {

    
    int n;
    int highestDegreePresent = 0;

     printf("Enter the number of polynomials: ");
    scanf("%d", &n);

    struct Polynomial polynomials[n];

   

    for (int i = 0; i < n; i++)
    {
        printf("Enter the highest degree of polynomial %d: ", i + 1);
        scanf("%d", &polynomials[i].highest_degree);
        polynomials[i].coefficients = (int*)malloc((polynomials[i].highest_degree + 1) * sizeof(int));
        for (int j = 0; j <= polynomials[i].highest_degree; j++)
        {
            printf("Enter the coefficient of x^%d: ", j);
            scanf("%d", &polynomials[i].coefficients[j]);
        }
        printf("\n");
    }



    for (int i = 0; i < n; i++)
    {
        printf("Polynomial %d: ", i + 1);
        for (int j = 0; j <= polynomials[i].highest_degree; j++)
        {
            printf("%dx^%d + ", polynomials[i].coefficients[j], j);
        }
        printf("\n");
    }
    

    for (int i = 0; i < n; i++)
    {
        if (polynomials[i].highest_degree > highestDegreePresent)
        {
            highestDegreePresent = polynomials[i].highest_degree;
        }   
    }

    int* sum = (int*)malloc((highestDegreePresent + 1) * sizeof(int));

    for (int i = 0; i <= highestDegreePresent; i++)
    {
        sum[i] = 0;

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= polynomials[i].highest_degree; j++)
        {
            sum[j] += polynomials[i].coefficients[j];
        }
    }

    for (int i = highestDegreePresent; i >=0; i--)
    {
        printf("%dx^%d + ", sum[i], i);
    }

    printf("\n\n\n");

    int highestDAM = 0;

    for (int i = 0; i < n; i++)
    {
        if (highestDAM == 0) {

            highestDAM = polynomials[i].highest_degree + 1;
        }
        else {
            highestDAM = highestDAM * (polynomials[i].highest_degree + 1);
        }

    }


    int* multiplication = (int*)malloc((highestDAM + 1) * sizeof(int));
    int indexOfHighestOrderPoly = 0;


    for (int i = 0; i < n; i++)
    {   
        if(polynomials[i].highest_degree > indexOfHighestOrderPoly) {
            indexOfHighestOrderPoly = i;
        }
    }

    for (int j = 0; j <= polynomials[indexOfHighestOrderPoly].highest_degree; j++)
    
    {
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (result == 0) {
                result = polynomials[i].coefficients[j];
            }
            else {
                result = result * polynomials[i].coefficients[j];
            }
        }
        multiplication[j] = result;
        result = 0;
        printf("\n");
    }

    for (int i = 0; i <= highestDAM; i++)
    {
        if (multiplication[i] != 0) {
        printf("%dx^%d + ", multiplication[i], i);
            
        }
    }


    return 0;


}