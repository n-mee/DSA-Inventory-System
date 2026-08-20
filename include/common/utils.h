#ifndef UTILS_H
#define UTILS_H

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms * 100)
#elif defined(__linux__)
    #include <unistd.h>
    #define sleep_ms(ms) sleep(ms);
#endif

#include "repository/inventory_database.h"

void clear_screen(unsigned int s);
int get_int_input(const char* msg_prompt);
double get_double_input(const char* msg_prompt);
int find_item_by_id(InventoryDatabase* inventory, int target_id);

#endif