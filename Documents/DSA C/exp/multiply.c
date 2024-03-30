#include <stdio.h>


// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    // Initializing elements of matrix mult to 0.
    int i,j,k;
    for (i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing it in result
    
    for ( i = 0; i < rowFirst; ++i) {
        for ( j = 0; j < columnSecond; ++j) {
            for (k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Function to display the matrix.
void displayMatrix(int matrix[][10], int row, int column) {
    int i, j ,k;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("%d", matrix[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10], rowFirst, columnFirst, rowSecond, columnSecond;
    int i,j,k;
    // Taking input for the first matrix.
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < rowFirst; ++i)
        for (j = 0; j < columnFirst; ++j)
            scanf("%d", &firstMatrix[i][j]);

    // Taking input for the second matrix.
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    // Check if multiplication is possible
    if (columnFirst != rowSecond) {
        printf("Error! column of the first matrix not equal to row of the second.\n");
        return -1; // Return an error code
    }

    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < rowSecond; ++i)
        for (j = 0; j < columnSecond; ++j)
            scanf("%d", &secondMatrix[i][j]);

    // Function call
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

    // Displaying the result
    printf("Output Matrix:\n");
    displayMatrix(result, rowFirst, columnSecond);

    return 0;
}
