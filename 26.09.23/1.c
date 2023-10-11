// Write a menu driven program to implement a doubly linked list with the following operations. 

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");

}

void insertElemStart() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertElemEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertElementPos() {

    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteElemStart() {

    struct Node* temp = head->next;
    temp->prev = NULL;
    head = temp;
    free(temp);
    displayList();
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
        printf("9. Delete at position\n\n");
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
                insertElemStart();
                break;
            case 4:
                insertElemEnd();
                break;
            case 5:
                insertElementPos();
                break;
            case 6:
               // searchElem();
                break;
            case 7:
               deleteElemStart();
                break;
            case 8:
               // deleteEnd();
                break;
            case 9:
               // deletePos();
                break;
        }
    }



    return 0;
}