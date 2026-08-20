#ifndef UTILS_H
#define UTILS_H

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms * 1000)
#elif defined(__linux__)
    #include <unistd.h>
    #define sleep_ms(ms) sleep(ms);
#endif

#include "repository/inventory_database.h"

/**
 * @brief clears the screen by moving the cursor to the first place in terminal
 * @param s seconds used for delay
 */
void clear_screen(unsigned int s);

/**
 * @brief generalized integer input catcher that parses string to int
 * @param msg_prompt string literal to print (it acts as printf before input)
 * @return returns the value of the parsed string to integer
 */
int get_int_input(const char* msg_prompt);

/**
 * @brief generalized double input catcher that parses string to double
 * @param msg_prompt string literal to print (it acts as printf before input)
 * @return returns the converted value from string input
 */
double get_double_input(const char* msg_prompt);

/**
 * @brief linear search algorithm for finding existing id in database
 * @param inventory reference to the inventory's database
 * @param target_id id to do a search on
 * @return -1 if fails, else it returns the if found
 */
int find_item_by_id(InventoryDatabase* inventory, int target_id);

#endif