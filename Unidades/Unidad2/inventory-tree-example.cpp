#include <iostream>
#include <string>

struct Item {
    std::string name;
    std::string type;
    int rarity;
    Item* left;
    Item* right;

    Item(std::string itemName, std::string itemType, int itemRarity)
        : name(itemName), type(itemType), rarity(itemRarity), left(nullptr), right(nullptr) {}
};

// Function to insert an item into the inventory based on rarity.
Item* insertItem(Item* root, std::string name, std::string type, int rarity) {
    if (root == nullptr) {
        return new Item(name, type, rarity);
    }

    if (rarity <= root->rarity) {
        root->left = insertItem(root->left, name, type, rarity);
    } else {
        root->right = insertItem(root->right, name, type, rarity);
    }

    return root;
}

// Function to display items in the inventory in ascending order of rarity.
void displayItems(Item* root) {
    if (root != nullptr) {
        displayItems(root->left);
        std::cout << "Name: " << root->name << ", Type: " << root->type << ", Rarity: " << root->rarity << std::endl;
        displayItems(root->right);
    }
}



int main() {
    Item* playerInventory = nullptr;

    playerInventory = insertItem(playerInventory, "Sword of Flames", "Weapon", 3);
    playerInventory = insertItem(playerInventory, "Health Potion", "Consumable", 1);
    playerInventory = insertItem(playerInventory, "Dragon Scale Armor", "Armor", 4);
    playerInventory = insertItem(playerInventory, "Magic Staff", "Weapon", 2);
    playerInventory = insertItem(playerInventory, "Elixir of Invisibility", "Consumable", 5);

    std::cout << "Player's Inventory:" << std::endl;
    displayItems(playerInventory);
    std::cout << "-------------------" << std::endl;

    // TODO: Add functions to delete items, search for items, and other inventory operations.

    return 0;
}
