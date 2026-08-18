#ifndef INVENTORY_DATABASE_H
#define INVENTORY_DATABASE_H

#include "model/product_model.h"

typedef struct {
    Product* product;
    int inventory_count;
    int inventory_capacity;
} InventoryDatabase;

int initialize_database(InventoryDatabase* db, int init_slots);
int expand_database(InventoryDatabase* db, int capacity);
int database_add_item(InventoryDatabase* db, Product new_item) ;
void delete_database(InventoryDatabase* db);

#endif