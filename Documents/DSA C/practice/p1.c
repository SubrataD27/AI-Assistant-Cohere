#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Function declarations
int findMaximum(int arr[], int n);
int findMinimum(int arr[], int n);
int findSum(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int values[SIZE];
    int choice, max, min, sum;

    // Input 10 values from the user
    printf("Enter %d values:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find Maximum\n");
        printf("2. Find Minimum\n");
        printf("3. Find Sum\n");
        printf("4. Print All Values\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                max = findMaximum(values, SIZE);
                printf("Maximum Value: %d\n", max);
                break;
            case 2:
                min = findMinimum(values, SIZE);
                printf("Minimum Value: %d\n", min);
                break;
            case 3:
                sum = findSum(values, SIZE);
                printf("Sum of All Values: %d\n", sum);
                break;
            case 4:
                printArray(values, SIZE);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

// Function to find the maximum value
int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value
int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the sum of all values
int findSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to print all values in the array
void printArray(int arr[], int n) {
    printf("Values in the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
