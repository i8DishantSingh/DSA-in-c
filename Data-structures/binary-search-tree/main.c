#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode {
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

BstNode *getNewNode(int data) {
    BstNode *newNode = (BstNode*)malloc(sizeof(BstNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode *insert(BstNode *root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(BstNode *root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

int main() {
    BstNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 80);
    root = insert(root, 30);
    root = insert(root, 40);

    int n;
    printf("Enter a number for searching: ");
    scanf("%d", &n);

    if (search(root, n)) {
        printf("Number found\n");
    } else {
        printf("Number not found\n");
    }
    return 0;
}
