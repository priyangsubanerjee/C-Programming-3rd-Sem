#include<stdio.h>


int main() {

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr1[n], arr2[n];

    for (int i = n; i >= 0; i--)
    {
        printf("Enter the element for %d power ", i);
        scanf("%d", &arr1[i]);
    }

        for (int i = n; i >= 0; i--)
    {
        printf("Enter the element for %d power ", i);
        scanf("%d", &arr2[i]);
        }


        for (int i = n; i >= 0; i--)
        {
            printf("%dX^%d", arr1[i] + arr2[i], i);
        }
        
    return 0;

}