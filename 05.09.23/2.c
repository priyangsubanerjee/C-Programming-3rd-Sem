#include <stdlib.h>
#include <stdio.h>


struct  Node
{
    int data;
    struct Node *next;
};


struct Node* head = NULL;

int main() {

    struct  Node* temp = head;

    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);

        if(head == NULL)
        {
            temp = newNode;
            head = temp;
        }
        else {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    



    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    

    return 0;
}
