#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push() {
    int data;
    printf("Enter data to push: ");
    scanf("%d", &data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", data);
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow.\n");
        exit(1);
    }
    struct Node* temp = top;
    top = top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int ch;

    while (1) {
        printf("\nLinked Stack:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit");
                exit(0);
            default:
                printf("Invalid ch");
        }
    }
    return 0;
}