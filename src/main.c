#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cli/menus.h"
#include "input/input.h"
#include "cli/display.h"
#include "controller/controller.h"
#include "model/product_model.h"
#include "repository/inventory_database.h"

int main() {
    
    InventoryDatabase inventory;
    if (initialize_database(&inventory, 1) == 0) {
        printf("Failed to initialize database.\n");
        return 1;
    }

    bool running = true;
    int choice;

    while(running) {
        display_menu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) 
        {
            case 1:
                handle_display_items(&inventory, choice);
                break;
            case 2:
                handle_display_items(&inventory, choice);
                break;
            case 3:
                break;
            case 4:
                handle_display_items(&inventory, choice);
                break;
            case 5:
                handle_display_items(&inventory, choice);
                break;
            case 0:
                running = false;
                break;
            default: break; 
        }
    }

    delete_database(&inventory);

    return 0;
}