#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository/inventory_database.h"

/**
 * @brief centralized controller for main menu
 * @param inventory reference for inventory's database
 * @param choice the decider on what operation it should do depending on user input
 */
void route_menu_choice(InventoryDatabase* inventory, int choice);

#endif