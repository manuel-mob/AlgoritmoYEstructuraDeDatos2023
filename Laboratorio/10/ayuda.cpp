#include <iostream>
#include <vector>

using namespace std;


//Node for General Tree
struct TreeNode {
    int data;
    vector<TreeNode*> children;
};

//Node for Binary Tree
struct TreeNode2 {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode2(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    return 0;   
}