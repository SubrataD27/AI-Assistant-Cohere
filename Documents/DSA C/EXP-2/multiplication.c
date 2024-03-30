#include<stdio.h>
void multiply(int r1,int c1,int r2,int c2);
int main()
{
   int i,j,r1,c1,r2,c2;
   printf("Enter row and column of first matrix:");
   scanf("%d %d",&r1,&c1);
   printf("Enter row and column of second matrix:");
   scanf("%d %d",&r2,&c2);
   multiply(r1,c1,r2,c2);
   return 0; 
}
void multiply(int r1,int c1,int r2,int c2)
{
    int i,j,k,a[10][10],b[10][10],mul[10][10];
    if(c1==r2)
    {
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
      }
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("b[%d][%d]:",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            mul[i][j]=0;
            for(k=0;k<r2;k++)
            {
                mul[i][j]=mul[i][j]+a[i][k]*b[k][j];
            }
        }
      }
    printf("The Multiplied Matrix is :\n" );
     for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d\t",mul[j][i]);
        }
        printf("\n");
    }
    }
    else{
        printf("Dimensions do not match for multiplication.");
    }
}