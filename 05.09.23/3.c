#include <stdlib.h>
#include <stdio.h>


struct  Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;



void createList() {
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
            head = newNode;
        }
        else {
            struct Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
}


void displayList() {

    struct Node* temp = head;

    if(temp == NULL)
    {
        printf("\n\nThe linked list is empty.\n\n");
        return;
    }

    printf("\n\nThe linked list is: \n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\n\n");

}


void searchElem() {

    int elem;
    int pos = 0;
    printf("Enter the element to search: ");
    scanf("%d", &elem);

    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == elem)
        {
            printf("Element found at position %d.\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    printf("Element not found.\n");

}


void insertStart() {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

}


void insertEnd() {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    struct Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}


void insertAtPos() {

    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    struct Node* temp = head;


    if(temp == NULL)
    {
        head = newNode;
        return;
    }

    if(pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteStart() {

    struct Node* temp = head;
    head = head->next;
    free(temp);

}


void deleteEnd() {

    struct Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

}


void deletePos() {

    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    struct Node* temp = head;

    if(pos == 0)
    {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }

    struct Node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}


int main() {

    while (1 == 1)
    {
        int choice;
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at start\n");
        printf("4. Insert at end\n");
        printf("5. Insert at position\n");
        printf("6. Search\n");
        printf("7. Delete at start\n");
        printf("8. Delete at end\n");
        printf("9. Delete at position\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createList();
                break;
            case 2:
                displayList();
                break;
            case 3:
                insertStart();
                break;
            case 4:
                insertEnd();
                break;
            case 5:
                insertAtPos();
                break;
            case 6:
                searchElem();
                break;
            case 7:
                deleteStart();
                break;
            case 8:
                deleteEnd();
                break;
            case 9:
                deletePos();
                break;
        }
    }



    return 0;
}