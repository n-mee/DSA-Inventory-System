#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "repository/inventory_database.h"

void sort_by_category(InventoryDatabase* inventory);
int delete_item(InventoryDatabase* inventory, int target_id);
int update_item (InventoryDatabase* inventory, Product* target, int* target_id);

#endif