#include <stdio.h>

struct Imaginary
{
    int real;
    int imaginary;
};

float add(struct Imaginary a, struct Imaginary b) {
    float real = a.real + b.real;
    float imaginary = a.imaginary + b.imaginary;
    printf("The sum is %f + %fi", real, imaginary);
    return 0;
}

// multiply by address 


int main() {

    int n;
    printf("Enter the number of complex numbers: ");
    scanf("%d", &n);
    struct Imaginary nums[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the real part of the complex number");
        scanf("%d", &nums[i].real);
        printf("Enter the imaginary part of the complex number");
        scanf("%d", &nums[i].imaginary);
    }

    for (int i = 0; i < n; i++) {
        printf("Menu\n1. Add\n2. Multiply\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(nums[0], nums[1]);
            break;
        case 2:
            //multiply(&nums[0], &nums[1]);
            break;

        }

        return 0;
    }
}