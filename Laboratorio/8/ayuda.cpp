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

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    //cout << " data:" << data << "vs root->data:" << root->data << endl;
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 11);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 3);
    
    printTree(root);
    cout << endl;

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
    
    deleteNode(root,5);
    cout << endl;

    printTree(root);
    cout << endl;

    return 0;
}
