#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        
        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (value < current->data) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void printInorder() {
        inorderTraversal(root);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.printInorder(); // Output: 1 3 4 5 6 7 8 
    return 0;
}
