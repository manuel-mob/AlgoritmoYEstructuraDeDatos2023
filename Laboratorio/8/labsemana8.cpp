#include <iostream>
#include <ctime>
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

Node* insertNode(Node* root, int data) {
    if ( root == NULL ) {
        root = createNode(data);
    }
    else {
        if ( data < root->data ) {
            root->left = insertNode(root->left,data);
        }
        else {
            root->right = insertNode(root->right,data);
        }
    }
    return root;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

bool search(Node* root, int keyValue) {
    if ( root ==  NULL ) {
        return false;
    }
    else {
        if ( keyValue == root->data) {
            return true;
        }
        else {
            if (keyValue < root->data ){
                return search(root->left,keyValue);
            }
            else {
                return search(root->right,keyValue);
            }
        }
    }
    return false;
}

int findMin(Node* root){
    if ( root->left == NULL ) {
        return root->data;
    }
    return findMin(root->left);
}

int findMax(Node* root){
    if ( root->right == NULL ) {
        return root->data;
    }
    return findMax(root->right);
}

Node* delete(Node* root,int deleteValue) {
    if ( root ==  NULL ) {
        //return false;
    }
    else {
        if ( deleteValue == root->data) {
            //return true;
        }
        else {
            if (deleteValue < root->data ){
                //return search(root->left,keyValue);
            }
            else {
                //return search(root->right,keyValue);
            }
        }
    }
    //return ;
}

int main(int argc, char* argv[]) {
    Node* root = NULL;
    int number;
    int total = atoi (argv[1]);    
    if ( total > 100 ) {
        cout << "Exit, argv > 100";
        return 0;
    }
    srand(time(0));
    for(int i = 0 ;  i < total ; i++) {
        number = 1+ (rand() % 100);
        cout << number << ", "; 
        root = insertNode(root,number);
    }
    cout << endl;

    cout << "Search:";
    cin >> number;
    if (search(root,number))
        cout << "Exists: " << number << endl;
    else 
        cout << "Sorry" << endl;
    

    cout << "Min value is:" << findMin(root) << endl;
    cout << "Max value is:" << findMax(root) << endl;

    printTree(root);
    return 0;
}