// Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.

#include<stdio.h>

struct Employee
{
    int emp_id;
    char name[20];
    char designation[20];
    float basic_salary;
    float hra;
    float da;
};


int main() {

    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d\n", i + 1);
        printf("Enter the employee id: ");
        scanf("%d", &emp[i].emp_id);
        printf("Enter the name of the employee: ");
        scanf("%s", emp[i].name);
        printf("Enter the designation of the employee: ");
        scanf("%s", emp[i].designation);
        printf("Enter the basic salary of the employee: ");
        scanf("%f", &emp[i].basic_salary);
        printf("Enter the hra of the employee: ");
        scanf("%f", &emp[i].hra);
        printf("Enter the da of the employee: ");
        scanf("%f", &emp[i].da);
    }


    printf("\n\nEmployee information\n\n");

    for (int i = 0; i < n; i++)
    {
        float grossSalary = emp[i].basic_salary + emp[i].basic_salary * emp[i].hra / 100 + emp[i].basic_salary * emp[i].da / 100;
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic salary: %f\n", emp[i].basic_salary);
        printf("HRA: %f%\n", emp[i].hra);
        printf("DA: %f%\n", emp[i].da);
        printf("DA: %f%\n", emp[i].da);
        printf("Gross salary: %f\n", grossSalary);

    }


    return 0;
}