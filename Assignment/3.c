// Add two sparse matrices represented using linked list.

#include<stdio.h>
#include<stdlib.h>

struct triplet
{
    int row;
    int col;
    int val;
    struct triplet *next;
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


void add(struct triplet *t1, struct triplet *t2, struct triplet *t3)
{
    if (t1->row != t2->row || t1->col != t2->col)
    {
        printf("Invalid dimensions\n");
        exit(1);
    }
    t3->row = t1->row;
    t3->col = t1->col;
    t3->val = 0;
    int i, j;
    for (i = 0; i < t1->row; i++)
    {
        for (j = 0; j < t1->col; j++)
        {
            if (t1->row == i && t1->col == j)
            {
                t3->val += t1->val;
            }
            if (t2->row == i && t2->col == j)
            {
                t3->val += t2->val;
            }
        }
    }
}


int main()
{
    struct triplet *t1 = (struct triplet *)malloc(sizeof(struct triplet));
    struct triplet *t2 = (struct triplet *)malloc(sizeof(struct triplet));
    struct triplet *t3 = (struct triplet *)malloc(sizeof(struct triplet));
    read(t1);
    read(t2);
    add(t1, t2, t3);
    display(t3);
    return 0;
}