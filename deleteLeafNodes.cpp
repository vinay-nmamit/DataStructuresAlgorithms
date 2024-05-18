// Delete leaf nodes with a given target value
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

bool isLeaf(TreeNode* root){
    return root->left == nullptr && root->right == nullptr;
}

TreeNode* deleteLeaf(TreeNode* root, int target){
    if(root == NULL) return 0;

    root->left = deleteLeaf(root->left, target);
    root->right = deleteLeaf(root->right, target);

    return isLeaf(root) && root->val == target ? nullptr : root;
}