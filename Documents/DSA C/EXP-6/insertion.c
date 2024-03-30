#include<stdio.h>
#include<stdlib.h>

void insertion(int[], int);

int main() {
    int a[100];
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    insertion(a, n);

    return 0;
}

void insertion(int a[], int n) {
    int i, temp, ptr;
    for (i = 1; i < n; i++) {
        temp = a[i];
        ptr = i - 1;
        while (temp < a[ptr] && ptr >= 0) {
            a[ptr + 1] = a[ptr];
            ptr--;
        }
        a[ptr + 1] = temp;
    }

    printf("The sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
