// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include<stdio.h>
#include<stdlib.h>

int main() {

    int n, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 2; j < arr[i]; j++)
        {
            if(arr[i] % j == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) sum += arr[i];
    }

    printf("The sum is %d", sum);

    free(arr);




    return 0;
}