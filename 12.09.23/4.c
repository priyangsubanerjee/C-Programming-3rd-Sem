#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        } else if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    return dummy.next;
}

void splitList(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(struct Node** head) {
    struct Node* current = *head;
    struct Node* list1;
    struct Node* list2;

    if (current == NULL || current->next == NULL) {
        return;
    }

    splitList(current, &list1, &list2);
    mergeSort(&list1);
    mergeSort(&list2);
    *head = mergeSortedLists(list1, list2);
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, data;

    printf("Enter the number of nodes in list 1: ");
    scanf("%d", &n1);

    printf("Enter the elements for list 1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insert(&list1, data);
    }

    printf("Enter the number of nodes in list 2: ");
    scanf("%d", &n2);

    printf("Enter the elements for list 2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insert(&list2, data);
    }

    struct Node* mergedList = mergeSortedLists(list1, list2);
    mergeSort(&mergedList);
    printf("Merged and sorted list: ");
    display(mergedList);

    return 0;
}
