#include <iostream>
#include <queue>
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

// DFS search function
Node* DFS(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    Node* left_result = DFS(root->left, value);
    if (left_result != NULL) {
        return left_result;
    }
    Node* right_result = DFS(root->right, value);
    if (right_result != NULL) {
        return right_result;
    }
    return NULL;
}

// BFS search function
Node* BFS(Node* root, int value) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->data == value) {
            return current;
        }
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    return NULL;
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

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void printTreeWithSpaces(Node* root, int space = 0, int gap = 4) {
    if (root == nullptr) {
        return;
    }
    space += gap;
    printTreeWithSpaces(root->right, space, gap);
    std::cout << std::endl;
    for (int i = gap; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;
    printTreeWithSpaces(root->left, space, gap);
}


void preOrderTraversal(Node* root, int indent = 0) {
    if (root == nullptr) return; // base case
    for (int i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << root->data << endl;
    preOrderTraversal(root->left, indent + 4); // recursively traverse the left subtree
    preOrderTraversal(root->right, indent + 4); // recursively traverse the right subtree
}

void printSeparator(){
    cout << "-----------------------------------" << endl;
}

int main() {
    Node* root = NULL;
    Node* valueFind = NULL;
    root = insert(root, 5);
    printTreeWithSpaces(root);
    printSeparator();
    root = insert(root, 8);
    printTreeWithSpaces(root);
    printSeparator();
    
    root = insert(root, 3);
    preOrderTraversal(root);
    printSeparator();
    
    root = insert(root, 11);
    printTreeWithSpaces(root);
    printSeparator();
    
    root = insert(root, 9);
    printTreeWithSpaces(root);
    printSeparator();
    
    root = insert(root, 1);
    printTreeWithSpaces(root);
    printSeparator();
    
    root = insert(root, 3);
    printTreeWithSpaces(root);
    printSeparator();
    
    preOrderTraversal(root);
    printSeparator();

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
    
    printTreeWithSpaces(root);

    //deleteNode(root,5);
    cout << endl;

    valueFind = BFS(root,1);
    cout << endl;
    if (valueFind)
        cout << "1 is in the tree." << endl;
    else
        cout << "7 is not in the tree." << endl;
    
    valueFind = DFS(root,8);
    if (valueFind)
        cout << "8 is in the tree." << endl;
    else
        cout << "8 is not in the tree." << endl;
    

    printTree(root);
    cout << endl;

    return 0;
}
