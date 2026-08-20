#include <stdlib.h>
#include <string.h>
#include "common/utils.h"
#include "service/inventory_service.h"

static int compare_by_category(const void* a, const void* b) 
{
    const Product* itemA = (const Product*)a;
    const Product* itemB = (const Product*)b;

    return strcmp(itemA->category, itemB->category);
}

void sort_by_category(InventoryDatabase* inventory) 
{
    if (inventory == NULL || inventory->inventory_count == 0) return;

    qsort(
          inventory->product, 
          inventory->inventory_count,
          sizeof(Product),
          compare_by_category
        );
}

int delete_item(InventoryDatabase* inventory, int target_id) {
    if (inventory == NULL) return 0;

    int found_index = find_item_by_id(inventory, target_id);
    if (found_index == -1) return 0;

    for (int i = found_index; i < inventory->inventory_count - 1; i++) {
        inventory->product[i] = inventory->product[i + 1];
    }
    inventory->inventory_count--;

    if (inventory->inventory_count > 0) 
    {
        Product* tmp = (Product*)realloc(inventory->product, inventory->inventory_count * sizeof(Product));

        if (tmp != NULL) 
        {
            inventory->product = tmp;
            inventory->inventory_capacity = inventory->inventory_count;
        }
    } 
    else 
    {
        free(inventory->product);
        inventory->product = NULL;
        inventory->inventory_capacity = 0;
    }

    return 1;
}

int update_item (InventoryDatabase* inventory, Product* target, int* target_id) 
{
    if (inventory == NULL || target_id == NULL) return -1;

    int found_id = find_item_by_id(inventory, *target_id);
    if (found_id == -1) return -1;

    inventory->product[found_id] = *target;
    inventory->product[found_id].itemId = *target_id;

    return 1;
}