#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int productNo;
    char name[100];
    float cost;
} Product;

int main() {
    int N, i;
    Product *products;

    printf("Enter the number of products: ");
    scanf("%d", &N);
    products = (Product *)malloc(N * sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for(i = 0; i < N; i++) {
        printf("Enter details for product %d\n", i + 1);
        printf("Product No: ");
        scanf("%d", &products[i].productNo);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Cost: ");
        scanf("%f", &products[i].cost);
    }

    printf("\nProducts with cost between 100 and 1000 rupees:\n");
    for(i = 0; i < N; i++) {
        if(products[i].cost >= 100 && products[i].cost <= 1000) {
            printf("Product No: %d, Name: %s, Cost: %.2f\n",
                   products[i].productNo, products[i].name, products[i].cost);
        }
    }
      free(products);
     return 0;
}
