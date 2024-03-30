#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
void displayQueue(struct Queue* q);
int isEmpty(struct Queue* q);

int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exiting.\n");
                // Free memory and exit
                while (!isEmpty(q)) {
                    dequeue(q);
                }
                free(q);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        printf("%d enqueued to queue\n", value);
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void displayQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

