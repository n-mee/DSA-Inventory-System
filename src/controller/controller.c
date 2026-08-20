#include <stdio.h>
#include "input/input.h"
#include "cli/display.h"
#include "common/utils.h"
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

static void handle_deletion(InventoryDatabase* inventory) {

    if (inventory == NULL) {
        printf("[!] ERROR: System database returned NULL.\n");
        return;
    }

    if (inventory->inventory_count == 0) {
        printf("[!] ERROR: System datbase is empty.\n");
        return;
    }

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    int target_id = get_int_input("Enter target item ID: ");

    if (delete_item(inventory, target_id) == 0){
        printf("An error has occured during deletion of the item\n");
        return;
    }

    printf("[+] Operation Success!\n");
}

// void handle_search_by_id(InventoryDatabase* inventory) {
//     if (inventory == NULL) {
//         printf("[!] ERROR: Database is empty.\n");
//         return;
//     }

//     int item_id = get
// }

static void update_item_info(InventoryDatabase* inventory) {
    if (inventory == NULL) {
        printf("[!] ERROR: Database is Null.\n");
        return;
    }

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    int target_id = get_int_input("Enter target ID: ");

    Product tmp = {0};

    if (update_item(inventory, &tmp, &target_id) == -1) {
        printf("[!] ERROR: An error occured during updating process.\n");
        return;
    }

    printf("[+] Operation success!\n");
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
        case 3:
            break;
        case 4:
            handle_insertion(inventory);
            break;
        case 5:
            update_item_info(inventory);
            break;
        case 6:
            handle_deletion(inventory);
        default: break;
    }
}