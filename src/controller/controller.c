#include <stdio.h>
#include "input/input.h"
#include "cli/display.h"
#include "service/inventory_service.h"
#include "controller/controller.h"

static void handle_insertion(InventoryDatabase* inventory) {
    if (inventory == NULL) return;

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    Product new_item = {0};

    if (get_item_credentials(&new_item) == 0) return;

    if (database_add_item(inventory, new_item) == 0) {
        printf("\nEn error occured during data insertion.\n");
        return;
    }

    printf("\nInsertion Completed Successfully\n");
}

void handle_display_items(InventoryDatabase* inventory, int choice) 
{
    switch (choice) 
    {
        case 1:
            view_render_table(inventory);
            break;
        case 2:
            sort_by_category(inventory);
            view_render_table(inventory);
            break;
        case 4:
            handle_insertion(inventory);
            break;
        default: break;
    }
}