//Display the elements in a circular linked list that follows a prime no values node.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node* head = NULL;

void insert(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct node* ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
    }
}


int isPrime(int data)
{
    int flag = 0;
    for(int i=2;i<=data/2;i++)
    {
        if(data%i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        return 1;
    }
    else {
        return 0;
    }

    
}



void display()
{
    struct node* ptr = head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(ptr->next != head)
        {
           // if ptr->data is prime print ptr->next->data
            if (isPrime(ptr->data) == 1) {
                printf("%d ", ptr->next->data);
            }
            ptr = ptr->next;
        }
        if (isPrime(ptr->data) == 1) {
            printf("%d ", ptr->next->data);
            
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter the element %d: ",i+1);
        scanf("%d", &data);
        insert(data);
    }
    printf("The elements in the circular linked list are: ");
    display();
    return 0;
}