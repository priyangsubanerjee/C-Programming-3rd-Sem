#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

int display() {
    struct Node* temp = head;

    if(temp == NULL)
    {
        printf("\n\nThe linked list is empty.\n\n");
        return 0;
    }
    
    printf("\n\nThe linked list is: \n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\n\n");

    return 0;
}

int insertElementStart() {
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = temp;
    head = newNode;

    return 0;
}

int insertElementEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (temp == NULL) {
        temp = newNode;
        return 0;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return 0;
}

int insertElementPos() {

    int pos = 0;
    int max = 0;
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    struct Node* endTemp = head;

    printf("Enter position choice: ");
    scanf("%d", &pos);


    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

}

int searchElement() {
    int s;
    struct Node* temp = head;
    printf("Enter the elem to search");
    scanf("%d", &s);
    if (temp == NULL) {
        printf("No list present");
    }
    else {
        int index = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            index ++;
        }
        
    }

}

int menu() {

        printf("\n");
        printf("1. Display the linked list\n");
        printf("2. Insert an element at the beginning\n");
        printf("3. Insert an element at the end\n");
        printf("4. Search for a number\n");
        printf("5. Enter element at pos\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:     
            display();
            break;
        case 2:     
            insertElementStart();
            break;
        case 3:     
            insertElementEnd();
            break;
        case 4:     
            searchElement();
            break;
        case 5:     
            insertElementPos();
            break;
        default:
            break;
        }

        menu();

        return 0;
}

int main() {

    int n = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // taking inputs

    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    // calling menu function recurisvely
    
    menu();

    return 0;
}