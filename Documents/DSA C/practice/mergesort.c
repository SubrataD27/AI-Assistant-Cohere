#include <stdio.h>
#include <stdlib.h>
int main()
{ 
    void merge(int [],int []);
    int a[5],b[5],c[10];
    int i,j;
    printf("Enter five values for the first array");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    
    printf("Enter five values for the second array");
    for(i=0;i<5;i++)
    scanf("%d",&b[i]);
    merge(a,b);
}
void merge(int a[],int b[]){
    int i,j,k=0,c[10];
    for(i=0,j=0;i<5 && j<5;)
    {
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<5){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<5){
        c[k]=b[j];
        k++;
        j++;
    }
    printf("\nThe Sorted Array:");
    for(i=0;i<10;i++)
    printf("%d ",c[i]);
}
