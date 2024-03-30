#include<stdio.h>
void sum(int r,int c);
int main()
{
   int i,j,r,c;
   printf("Enter row and column of first matrix:");
   scanf("%d %d",&r,&c);
   sum(r,c);
   return 0; 
}
void sum(int r,int c)
{
    int i,j,a[10][10],sum;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        sum = 0;
        for(j=0;j<c;j++)
        {
            sum = sum + a[i][j];
        }
        printf("The Sum of Elements of a Rows in a Matrix =  %d \n", sum );
    }
    
}