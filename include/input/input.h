#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include "model/product_model.h"

int get_input(const char* msg, char* target, size_t size);
int get_item_credentials(Product* new_item);
int get_item_id(int* id);

#endif