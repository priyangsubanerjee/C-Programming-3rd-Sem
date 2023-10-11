// 1. Implement stack using linked list.

#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


struct Node* head = NULL;
int top = -1;


int push(int data) {
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        top++;
        return top;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        top++;
    }

    return top;

}

int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        printf("Top element is: %d\n", temp->data);
        return temp->data;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    else {
        if (top == 0) {
            top--;
            printf("Popped element is: %d\n", head->data);
            head = NULL;
            return head->data;
        }
        
    }
}

void menu() {
    int choice;
    printf("\n\n1. Push\n2. Pop\n3. Peek\n4. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:     
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        push(data);
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    default:
        break;
    }
}

int main() {

    while(1) {
        menu();
    }

    return 0;
}