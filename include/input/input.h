#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include "model/product_model.h"

/**
 * @brief handles string input to reduce fgets redundancy
 * @param msg string literal reference for printing prompt
 * @param target target string var to pass the value
 * @param size size of string (char var[])
 * @return 0 if operation fails, 1 if successful
 */
int get_input(const char* msg, char* target, size_t size);

/**
 * @brief handles the input of getting item credentials
 * @param new_item pointer to the instance of struct (tmp) to pass its value
 * @return 0 if operation fail, 1 if successful
 */
int get_item_credentials(Product* new_item);

/**
 * @brief handles getting input for updating item information
 * @param info pointer to the temporary instance of struct (tmp) to pass its value
 * @return -1 if fail, 1 if successful
 */
int get_new_info(Product* info);

#endif