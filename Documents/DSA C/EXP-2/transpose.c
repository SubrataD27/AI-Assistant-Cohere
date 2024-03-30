#include <stdio.h>
void transpose(int r, int c);
int main()
{
    int i, j, r, c;
    printf("Enter row and column of first matrix:");
    scanf("%d %d", &r, &c);
    transpose(r, c);
    return 0;
}
void transpose(int r, int c)
{
    int i, j, a[10][10], sum;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The transpose of the Matrix is =\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }
}