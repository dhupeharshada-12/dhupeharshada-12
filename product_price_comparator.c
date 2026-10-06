#include <stdio.h>

struct Product {
    char name[50];
    float price;
};

int main() {
    struct Product products[3];
    int cheapest = 0;

    printf("===== PRODUCT PRICE COMPARATOR =====\n");

    for (int i = 0; i < 3; i++) {
        printf("\nEnter product %d name: ", i + 1);
        scanf(" %[^\n]", products[i].name);

        printf("Enter price: ");
        scanf("%f", &products[i].price);
    }

    for (int i = 1; i < 3; i++) {
        if (products[i].price < products[cheapest].price) {
            cheapest = i;
        }
    }

    printf("\n===== PRICE COMPARISON =====\n");

    for (int i = 0; i < 3; i++) {
        printf("%s : Rs. %.2f\n",
               products[i].name,
               products[i].price);
    }

    printf("\nLowest Price:\n");
    printf("%s - Rs. %.2f\n",
           products[cheapest].name,
           products[cheapest].price);

    return 0;
}
