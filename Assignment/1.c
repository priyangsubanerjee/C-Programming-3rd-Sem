//  Write a program to Add two sparse matrices represented using triplet

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

void add(struct triplet *t1, struct triplet *t2, struct triplet *t3)
{
    if(t1->row == t2->row && t1->col == t2->col)
    {
        t3->row = t1->row;
        t3->col = t1->col;
        t3->val = t1->val + t2->val;
    }
    else
    {
        printf("Invalid addition\n");
        exit(0);
    }
}

int main()
{
    struct triplet t1, t2, t3;
    read(&t1);
    read(&t2);
    add(&t1, &t2, &t3);
    display(&t3);
    return 0;
}