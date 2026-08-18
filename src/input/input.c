#include <stdio.h>
#include <string.h>
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
