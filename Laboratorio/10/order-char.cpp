#include <iostream>
using namespace std;


struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->left->right->left = new TreeNode('H');
    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');
    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
    
}

int main() {
    TreeNode* root = createTree();
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
