//  Distribute coins or candies evenly in a Binary Tree
#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode () : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

int helper(TreeNode* root, int &ans){
    if(root == NULL) return 0;

    int l = helper(root->left, ans);
    int r = helper(root->right, ans);

    ans += abs(l) + abs(r);

    return root->val + l + r - 1;
}

int distrubuteCoinsBT(TreeNode* root){
    int ans = 0;
    helper(root, ans);
    return ans;
}