// wap to merge 2 linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main() {

    struct node *head1, *head2, *temp, *newnode, *tail;
    int n, i;

    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));

    printf("Enter the number of nodes: ");
    scanf("%d", &n);


    head1->next = NULL;
    head2->next = NULL;

    tail = head1;

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }

    tail = head2;

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }


    temp = head1;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (temp->data != 0) {
                printf("%d ", temp->data);
            }
        }
        temp = temp->next;
    }

    temp = head1;

    while (temp != NULL) {
        if (temp->data % 2 != 0) {
           if (temp->data != 0) {
                printf("%d ", temp->data);
            }
        }
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (temp->data != 0) {
                printf("%d ", temp->data);
            }
        }
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL) {
        if (temp->data % 2 != 0) {
           if (temp->data != 0) {
                printf("%d ", temp->data);
            }
        }
        temp = temp->next;
    }

    


    return 0;
}