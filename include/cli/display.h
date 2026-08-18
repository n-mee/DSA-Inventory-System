#ifndef DISPLAY_H
#define DISPLAY_H

#include "model/product_model.h"
#include "repository/inventory_database.h"

void print_product(int product_count, Product* item);
void view_render_table(const InventoryDatabase* inventory);

#endif