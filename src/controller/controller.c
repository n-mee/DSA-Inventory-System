#include "input/input.h"
#include "cli/display.h"
#include "service/inventory_service.h"
#include "controller/controller.h"


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
        default: break;
    }
}