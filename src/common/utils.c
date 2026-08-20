#include <stdio.h>
#include <stdlib.h>
#include "common/utils.h"


void clear_screen(unsigned int s) {
    sleep_ms(s);

    printf("\033[H\033[2J");
    fflush(stdout);
}

int find_item_by_id(InventoryDatabase* inventory, int target_id) {
    if (inventory == NULL) return -1;


    for (int i = 0; i < inventory->inventory_count; i++) {
        if (inventory->product[i].itemId == target_id) {
            return i;
        }
    }

    return -1;
}