#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
    int data;
    struct node *next;
} node;


node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(node** head, int value) {
    node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(node** head, int value) {
    node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteNode(node** head, int value) {
    node* temp = *head;
    node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void displayList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List: ");
    displayList(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    displayList(head);

    deleteNode(&head, 50); // Value not in list

    return 0;
}
