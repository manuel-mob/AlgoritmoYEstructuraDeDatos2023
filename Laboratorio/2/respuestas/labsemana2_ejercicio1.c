#include <stdio.h>

#define MAX_ITEMS 100   // maximum number of items that can be collected

int main() {
    // declare variables
    int items[MAX_ITEMS] = {0};
    int num_items, i, item_id;

    // get input from user
    printf("Enter the number of collected items (up to %d): ", MAX_ITEMS);
    scanf("%d", &num_items);
    if (num_items > MAX_ITEMS) {
        printf("Error: maximum number of items exceeded.\n");
        return 1;
    }
    for (i = 0; i < num_items; i++) {
        printf("Enter the ID number of collected item #%d: ", i+1);
        scanf("%d", &item_id);
        if (item_id < 0 || item_id >= MAX_ITEMS) {
            printf("Error: invalid item ID number.\n");
            return 1;
        }
        items[item_id]++;
    }

    // display summary of collected items
    printf("\nSummary of collected items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i] > 0) {
            printf("Item #%d: %d\n", i, items[i]);
        }
    }

    return 0;
}

