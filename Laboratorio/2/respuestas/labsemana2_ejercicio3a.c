#include <stdio.h>

#define INVENTORY_SIZE 10

int* add_item(int inventory[], int item_type) {
    // Check if item type already exists in inventory
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] == item_type) {
            inventory[i]++;
            return inventory;
        }
    }

    // If item type not found, add it to inventory
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] == 0 || inventory[i] == -1) {
            inventory[i] = item_type;
            return inventory;
        }
    }

    // If inventory is full and item type not found, do not add it
    printf("Inventory full. Cannot add item.\n");
    return inventory;
}

int* remove_item(int inventory[], int item_type) {
    // Check if item type exists in inventory
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] == item_type) {
            inventory[i]--;
            if (inventory[i] == 0) {
                inventory[i] = -1;
            }
            return inventory;
        }
    }

    // If item type not found in inventory, do not remove it
    printf("Item not found in inventory. Cannot remove item.\n");
    return inventory;
}

int main() {
    int inventory[INVENTORY_SIZE] = {0};

     // Display current inventory
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");


    // Add some items to inventory
    add_item(inventory, 1);

     // Display current inventory
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    add_item(inventory, 2);

     // Display current inventory
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    add_item(inventory, 1);

    printf("-------------\n");

    add_item(inventory, 0);
    // Display current inventory
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    // Remove an item from inventory
    remove_item(inventory, 1);

    // Display current inventory
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    return 0;
}

