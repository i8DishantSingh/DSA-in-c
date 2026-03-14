#include<stdio.h>


#define MAX 1000

typedef struct{
    int data[MAX];
    int top;
}type_stack;


// Initialize stack
void initStack(type_stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(type_stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(type_stack *s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
int push(type_stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return 0;
    }
    s->data[++(s->top)] = value;
    return 1;
}

// Pop an element from the stack
int pop(type_stack *s, int *popped) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return 0;
    }
    *popped = s->data[(s->top)--];
    return 1;
}

// Display elements in the stack
void display(type_stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; --i) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    type_stack stack;
    initStack(&stack);
    int choice, value, popped;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // clear invalid input
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (push(&stack, value)) {
                    printf("Pushed %d\n", value);
                }
                break;
            case 2:
                if (pop(&stack, &popped)) {
                    printf("Popped %d\n", popped);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


