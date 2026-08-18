#include <stdio.h>
#include <string.h>
#include "model/product_model.h"
#include "input/input.h"

int get_input(const char* msg, char* target, size_t size){
    printf("%s", msg);
    if (fgets(target, size, stdin) == NULL) {
        printf("[!] ERROR: Something went wrong.\n");
        return 0;
    }
    target[strcspn(target, "\n")] = '\0';
    return 1;
}

int get_item_credentials(Product* new_item) {
    char buffer[100];

    if (get_input("\nEnter product name: ", new_item->itemName, sizeof(new_item->itemName)) == 0 ||
        get_input("\nEnter product category: ", new_item->category, sizeof(new_item->category)) == 0) {
        return 0;
    }

    printf("Enter the product's ID: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, " %d", &new_item->itemId);

    printf("Enter initial price: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer," %lf", &new_item->price);

    return 1;
}

int get_item_id(int* id) {
    char buffer[100];

    printf("Enter product ID: ");

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    if(sscanf(buffer, " %d", id) != 1){
        return 0;
    }

    return 1;
}
