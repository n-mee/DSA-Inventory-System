#include <stdlib.h>
#include <string.h>
#include "repository/inventory_database.h"


int initialize_database(InventoryDatabase* db, int init_slots) 
{
    db->inventory_capacity = init_slots;
    db->inventory_count = 0;

    db->product = calloc(init_slots, sizeof(Product));
    return (db->product != NULL);
}

int database_add_item(InventoryDatabase* db, Product new_item) 
{
    if (db->inventory_count >= db->inventory_capacity) 
    {
        if (expand_database(db, db->inventory_capacity * 2) == 0) 
        {
            return 0;
        }
    }

    int index = db->inventory_count;
    db->product[index] = new_item;

    db->inventory_count++;
    return db->product[index].itemId;
}

int expand_database(InventoryDatabase* db, int capacity) 
{
    if (capacity > db->inventory_capacity) 
    {
        Product* tmp = realloc(db->product, capacity * sizeof(Product));
        if (tmp == NULL) return 0;
        db->product = tmp;

        int new_space = capacity - db->inventory_capacity;
        memset(db->product + db->inventory_capacity, 0, new_space * sizeof(Product));
        
        db->inventory_capacity = capacity;
    }
    return 1;
}

void delete_database(InventoryDatabase* db) 
{
    if (db->product != NULL) 
    {
        free(db->product);
        db->product = NULL;
    }
    db->inventory_count = 0;
    db->inventory_capacity = 0;
}
