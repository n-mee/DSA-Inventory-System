#include <stdio.h>
#include <string.h>
#include "model/product_model.h"
#include "input/input.h"

int get_input(const char* msg, char* target, size_t size){
    printf("%s", msg);
    if (fgets(target, size, stdin) == NULL) {
        printf("[!] ERROR: Something went wrong.\n");
        return 0;
    }
    target[strcspn(target, "\n")] = '\0';
    return 1;
}

int get_item_credentials(Product* new_item) {

    if (get_input("Enter product name: ", new_item->itemName, sizeof(new_item->itemName)) == 0 ||
        get_input("Enter product category: ", new_item->category, sizeof(new_item->category)) == 0) {
        return 0;
    }

    new_item->itemId = get_int_input("Enter new ID: ");
    new_item->price = get_double_input("Enter initial price: ");

    return 1;
}

int get_int_input(const char* msg_prompt) {
    char buffer[100];
    int out_n;

    while (1) {
        printf("%s", msg_prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {

            if (strchr(buffer, '\n') == NULL) {
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }

            if (sscanf(buffer, " %d", &out_n) == 1) {
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

int get_new_info(Product* info) {
    
    if (get_input("Enter new item name: ", info->itemName, sizeof(info->itemName)) == 0 ||
        get_input("Enter new item's category type: ", info->category, sizeof(info->category)) == 0) {
        return -1;
    }
    info->price = get_double_input("Enter new price: ");

    return 1;
}