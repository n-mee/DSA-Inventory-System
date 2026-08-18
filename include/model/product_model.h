#ifndef PRODUCT_MODEL_H
#define PRODUCT_MODEL_H

typedef struct {
    char itemName[128];
    char category[64];
    int itemId;
    double price;
} Product;

#endif