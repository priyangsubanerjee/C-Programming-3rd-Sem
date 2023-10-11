// Write a program to read two numbers and compare the numbers using function call by value and call by address.

#include<stdio.h>   

void compareByValue(int i, int j) {
    if(i > j) printf("%d is greater than %d", i, j);
    else if(i < j) printf("%d is smaller than %d", i, j);
    else printf("%d is equal to %d", i, j);
    return;
}

void compareByAddress(int *p, int *q) {
    if(*p > *q) printf("%d is greater than %d", *p, *q);
    else if(*p < *q) printf("%d is smaller than %d", *p, *q);
    else printf("%d is equal to %d", *p, *q);
    return;
}

int main() {

    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Comparing by value\n");
    compareByValue(a, b);
    printf("\nComparing by reference\n");
    compareByAddress(&a, &b);
    return 0;

}