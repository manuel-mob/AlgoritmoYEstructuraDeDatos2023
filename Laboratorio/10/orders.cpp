#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Pre-order traversal: Root -> Left -> Right
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// In-order traversal: Left -> Root -> Right
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform pre-order traversal
    std::cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // Perform in-order traversal
    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Perform post-order traversal
    std::cout << "Post-order traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
