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
    int i,j,a[10][10],sum,counter=0;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            if (a[i][j] == 0)
            {
                ++counter;
            }
        }
    }
    if (counter > (( r *  c ) / 2))
    {
        printf("The given matrix is sparse matrix \n");
    }
    else
        printf("The given matrix is not a sparse matrix \n");
    printf("There are %d number of zeros", counter);
}