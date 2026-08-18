#include <stdio.h>
#include "input/input.h"
#include "cli/display.h"
#include "repository/inventory_database.h"
#include "model/product_model.h"

void view_render_table(const InventoryDatabase* inventory) {
    if (inventory == NULL || inventory->inventory_count == 0) {
        printf("[!] This inventory is currently empty.\n");
        return;
    }

    printf("\n=======================================================================\n");
    printf("%-10s | %-25s | %-15s | %-10s\n", "Item ID", "Product Name", "Category Type", "Price");
    printf("\n-----------------------------------------------------------------------\n");

    for (int i = 0; i < inventory->inventory_count; i++) {
        printf("%-10d | %-25s | %-15s | ₱%-9.2f\n",
            inventory->product[i].itemId,
            inventory->product[i].itemName,
            inventory->product[i].category,
            inventory->product[i].price);
    }
    printf("=======================================================================\n");
}

void print_product(int product_count, Product* item) {
    for (int i = 0; i < product_count; i++) {
        printf("\nName: %s\nCategory: %s\nItem ID: %d\nPrice: %.2f\n", 
            item[i].itemName, item[i].category, item[i].itemId, item[i].price);
    }
}