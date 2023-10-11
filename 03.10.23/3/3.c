// WAP to display a single linked list in such a way that all even number followed by odd number.

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

int main() {

    struct node *head, *temp, *newnode, *tail;
    int n, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter the number of nodes: ");
    scanf("%d", &n);


    head->next = NULL;
    tail = head;

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }

    temp = head;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (temp->data != 0) {
                printf("%d ", temp->data);
            }
        }
        temp = temp->next;
    }

    temp = head;

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