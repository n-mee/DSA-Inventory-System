#include <stdlib.h>
#include "common/utils.h"

int find_item_by_id(InventoryDatabase* inventory, int target_id) {
    if (inventory == NULL) return -1;


    for (int i = 0; i < inventory->inventory_count; i++) {
        if (inventory->product[i].itemId == target_id) {
            return i;
        }
    }

    return -1;
}