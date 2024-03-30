
#include <stdio.h>

void mergeSortedArrays(int a[], int b[], int c[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge arrays a and b into c in sorted order
    while (i < 5 && j < 5) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Copy the remaining elements of a, if any
    while (i < 5) {
        c[k++] = a[i++];
    }

    // Copy the remaining elements of b, if any
    while (j < 5) {
        c[k++] = b[j++];
    }
}

int main() {
    int a[5], b[5], c[10];
    int i;

    // Input elements for the first array (a)
    printf("Enter 5 elements in ascending order for the first array (a):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    // Input elements for the second array (b)
    printf("Enter 5 elements in ascending order for the second array (b):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }

    // Merge sorted arrays a and b into array c
    mergeSortedArrays(a, b, c);

    // Print the merged and sorted array c
    printf("The merged and sorted array (c) is:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
