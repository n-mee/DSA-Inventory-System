#ifndef INVENTORY_DATABASE_H
#define INVENTORY_DATABASE_H

#include "model/product_model.h"

/**
 * @brief vector style database for dynamic memory allocation
 * @details Uses vector to resize by checking if count exceeded capacity
 */
typedef struct {
    Product* product;
    int inventory_count;
    int inventory_capacity;
} InventoryDatabase;

/**
 * @brief initializes database by allocating a new instance in ram using calloc
 * @param db pointer reference for database
 * @param init_slots decider on how much space on heap it should allocate too
 * @return 0 if fails, 1 if success
 */
int initialize_database(InventoryDatabase* db, int init_slots);

/**
 * @brief expands existing database by passing new size
 * @param db pointer reference to existing database
 * @param capacity new target space to allocate
 * @return 0 if fails, 1 if successful
 */
int expand_database(InventoryDatabase* db, int capacity);

/**
 * @brief adds new item in the database, expands it if space is out
 * @param db reference to existing database
 * @param new_item copied temporary struct on stack to be passed on for new account
 * @return ID of the new account, 0 if it fails
 */
int database_add_item(InventoryDatabase* db, Product new_item) ;

/**
 * @brief frees the database, thats it. It uses free() to free db and sets values to NULL so it cant be used again
 * @param db reference to existing database
 */
void delete_database(InventoryDatabase* db);

#endif