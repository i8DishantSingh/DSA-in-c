#include <stdio.h>
#include <stdlib.h>   

#define MAX 1000

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(node *start);

int main() {
    node *start = NULL;
    start = create_list(start);

    // Print the list to verify
    node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

node *create_list(node *start) {
    int n, i;
    node *new_node, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        new_node = (node *)malloc(sizeof(node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return start;
}
