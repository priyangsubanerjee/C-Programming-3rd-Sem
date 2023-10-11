#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

int main() {
    int n;
    struct Node* temp = head;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    int numArr[n];
    
    for (int i = 0; i < n; i++)
    {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &new_node->data);

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            struct Node* temp2 = head;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = new_node;
        }
    }

    int i = 0;
    temp = head;
    while (temp != NULL)
    {
        numArr[i] = temp->data;
        temp = temp->next;
        i++;
    }


    printf("\n\nThe reversed linked list is: \n");

    for (int i = n-1; i >= 0; i--)
    {
        printf("%d ", numArr[i]);
    }

}