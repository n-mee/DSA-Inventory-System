#ifndef DISPLAY_H
#define DISPLAY_H

#include "model/product_model.h"
#include "repository/inventory_database.h"

/**
 * @brief handles printing the entire inventory's existing items
 * @param inventory reference to inventory's database
 */
void view_render_table(const InventoryDatabase* inventory);

/**
 * @brief handles printing singular item in inventory
 * @param item direct access to item's model
 */
void view_render_single_item(const Product* item);

#endif