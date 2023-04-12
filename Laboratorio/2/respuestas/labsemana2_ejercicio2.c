#include <stdio.h>
#include <stdlib.h>

#define INVENTORY_SIZE 100   // maximum number of items in inventory

int* merge_inventories(int* inventory1, int* inventory2, int size) {
    int i;
    int* merged_inventory = (int*) malloc(size * sizeof(int));   // allocate memory for merged inventory
    if (!merged_inventory) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    for (i = 0; i < size; i++) {
        merged_inventory[i] = inventory1[i] + inventory2[i];   // merge inventories
    }

    return merged_inventory;
}

int main() {
    int inventory1[INVENTORY_SIZE] = {2, 4, 0, 1, 0};   // example inventory for player 1
    int inventory2[INVENTORY_SIZE] = {1, 0, 3, 2, 5};   // example inventory for player 2
    int* merged_inventory = NULL;
    int i;

    merged_inventory = merge_inventories(inventory1, inventory2, INVENTORY_SIZE);

    // print merged inventory
    printf("Merged inventory:\n");
    for (i = 0; i < INVENTORY_SIZE; i++) {
        printf("Item %d: %d\n", i+1, merged_inventory[i]);
    }

    // free allocated memory
    free(merged_inventory);

    return 0;
}

