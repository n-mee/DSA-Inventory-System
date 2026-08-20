#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cli/menus.h"
#include "input/input.h"
#include "cli/display.h"
#include "common/utils.h"
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
        choice = get_int_input("Enter your choice: ");
        clear_screen(2);

        switch (choice) 
        {
            case 1:
                route_menu_choice(&inventory, choice);
                clear_screen(1);
                break;
            case 2:
                route_menu_choice(&inventory, choice);
                clear_screen(6);
                break;
            case 3:
                route_menu_choice(&inventory, choice);
                clear_screen(1);
                break;
            case 4:
                route_menu_choice(&inventory, choice);
                clear_screen(1);
                break;
            case 5:
                route_menu_choice(&inventory, choice);
                clear_screen(1);
                break;
            case 6:
                route_menu_choice(&inventory, choice);
                clear_screen(1);
                break;
            case 0:
                clear_screen(3);
                printf("[+] System is exiting..\n");
                clear_screen(2);
                printf("[+] Thank you for checking out our system.\n");
                clear_screen(2);
                running = false;
                break;
            default:
                printf("[!] ERROR: Invalid choice.\n"); 
                break; 
        }
    }

    delete_database(&inventory);

    return 0;
}