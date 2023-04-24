#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL; 
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == data) {
        return true;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}


int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    
    if (search(root, 5)) {
        cout << "5 is in the tree." << endl;
    }
    else {
        cout << "5 is not in the tree." << endl;
    }
    
    if (search(root, 8)) {
        cout << "8 is in the tree." << endl;
    }
    else {
        cout << "8 is not in the tree." << endl;
    }
    
    if (search(root, 20)) {
        cout << "20 is in the tree." << endl;
    }
    else {
        cout << "20 is not in the tree." << endl;
    }
    
    printTree(root);

    return 0;
}
