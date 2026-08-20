#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "repository/inventory_database.h"

/**
 * @brief sorts existing items in database by category alphabetically using qsort(); <quick-sort>
 * @param inventory reference to inventory's database
 */
void sort_by_category(InventoryDatabase* inventory);

/**
 * @brief deletes a specific item in database by its ID
 * @param inventory reference to inventory's database
 * @param target_id target id that needs to be removed
 * @return 0 if operation fails, 1 if it succeeds
 */
int delete_item(InventoryDatabase* inventory, int target_id);

/**
 * @brief updates the current item that is index by its ID
 * @param inventory reference to inventory's database
 * @param target pointer temporary struct that contains new values
 * @param target_id reference to the account id that needs updating
 * @return -1 if fails, 1 if successful
 */
int update_item (InventoryDatabase* inventory, Product* target, int* target_id);

#endif