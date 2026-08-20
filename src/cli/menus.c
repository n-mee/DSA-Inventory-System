#include <stdio.h>
#include "cli/menus.h"

void display_menu() {
    printf("+---------------------------------------+\n");
    printf("|        INVENTORY SYSTEM CUTIE         |\n");
    printf("|        Authored by: mihkaela          |\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|   [1] Display all items               |\n");
    printf("|   [2] Display items per category      |\n");
    printf("|   [3] Search item by ID               |\n");
    printf("|   [4] Add new item                    |\n");
    printf("|   [5] Update Item Credentials         |\n");
    printf("|   [6] Delete item                     |\n");
    printf("|                                       |\n");
    printf("|   [0] Exit                            |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
}