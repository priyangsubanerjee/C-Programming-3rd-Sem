//  Write a program to Multiply two sparse matrices represented using triplet

#include<stdio.h>
#include<stdlib.h>

struct triplet
{
    int row;
    int col;
    int val;
};

void read(struct triplet *t)
{
    printf("Enter the row, column and value of the element: ");
    scanf("%d %d %d", &t->row, &t->col, &t->val);
}


void display(struct triplet *t)
{
    printf("Row: %d, Column: %d, Value: %d\n", t->row, t->col, t->val);
}

void multiply(struct triplet *t1, struct triplet *t2, struct triplet *t3)
{
    if (t1->col != t2->row)
    {
        printf("Invalid dimensions\n");
        exit(1);
    }
    t3->row = t1->row;
    t3->col = t2->col;
    t3->val = 0;
    int i, j, k;
    for (i = 0; i < t1->row; i++)
    {
        for (j = 0; j < t2->col; j++)
        {
            int sum = 0;
            for (k = 0; k < t1->col; k++)
            {
                if (t1->row == i && t1->col == k)
                {
                    sum += t1->val;
                }
                if (t2->row == k && t2->col == j)
                {
                    sum += t2->val;
                }
            }
            if (sum != 0)
            {
                t3->val = sum;
                display(t3);
            }
        }
    }
}

int main()
{
    struct triplet t1, t2, t3;
    read(&t1);
    read(&t2);
    multiply(&t1, &t2, &t3);
    display(&t3);
    return 0;
}