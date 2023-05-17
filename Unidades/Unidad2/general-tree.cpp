#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

TreeNode* createNode(int val) {
    TreeNode* newNode = new TreeNode(val);
    return newNode;
}

void insertNode(TreeNode* root, int val) {
    TreeNode* newNode = createNode(val);
    root->children.push_back(newNode);
}

bool searchNode(TreeNode* root, int val) {
    if (root == NULL) {
        return false;
    }
    if (root->val == val) {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++) {
        if (searchNode(root->children[i], val)) {
            return true;
        }
    }
    return false;
}

void deleteNode(TreeNode* root, int val) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        if (root->children[i]->val == val) {
            root->children.erase(root->children.begin() + i);
            return;
        }
    }
    for (int i = 0; i < root->children.size(); i++) {
        deleteNode(root->children[i], val);
    }
}

void printTree(TreeNode* root, int space = 0) {
    if (root == NULL) {
        return;
    }
    cout << string(space, ' ') << root->val << endl;
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i], space + 4);
    }
}

int main() {
    TreeNode* root = createNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root->children[0], 4);
    insertNode(root->children[0], 5);
    insertNode(root->children[1], 6);
    insertNode(root->children[1], 7);
    
    cout << "Printing the tree:" << endl;
    printTree(root);
    
    cout << "Deleting node with value 4" << endl;
    deleteNode(root, 4);
    printTree(root);
    
    cout << "Searching for node with value 6: ";
    if (searchNode(root, 6)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}
