#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
};

TreeNode* buildtree(const vector<string>& nodes){
    if(nodes.empty() || nodes[0] == "null"){
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    size_t index = 1;
    while(!q.empty() && index < nodes.size()){
        TreeNode* current = q.front();
        q.pop();

        if(nodes[index] != "null"){
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        }
        index++;

        if(index < nodes.size() && nodes[index] != "null"){
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        }
        index++;
    }
    return root;
}

int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}