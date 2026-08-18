#include <stdlib.h>
#include <string.h>
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