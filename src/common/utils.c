#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/utils.h"


void clear_screen(unsigned int s) {
    sleep_ms(s);

    printf("\033[H\033[2J");
    fflush(stdout);
}

int get_int_input(const char* msg_prompt) 
{
    char buffer[100];
    int out_n;

    while (1) {
        printf("%s", msg_prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) 
        {

            if (strchr(buffer, '\n') == NULL) 
            {
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }

            if (sscanf(buffer, " %d", &out_n) == 1) 
            {
                return out_n;
            }
        }
        printf("[!] ERROR: Enter valid input.\n");
    }
}

double get_double_input(const char* msg_prompt) {
    char buffer[100];
    double out_n;

    while (1) {
        printf("%s", msg_prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (strchr(buffer, '\n') == NULL) {
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }

            if (sscanf(buffer, " %lf", &out_n) == 1.00){
                return out_n;
            } 
        }
        printf("[!] ERROR: Enter valid input.\n");
    }
}


int find_item_by_id(InventoryDatabase* inventory, int target_id) {
    if (inventory == NULL) return -1;


    for (int i = 0; i < inventory->inventory_count; i++) {
        if (inventory->product[i].itemId == target_id) {
            return i;
        }
    }

    return -1;
}