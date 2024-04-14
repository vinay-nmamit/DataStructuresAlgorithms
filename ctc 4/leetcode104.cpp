/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes 
along the longest path from the root node down to the farthest leaf node */
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    size_t index = 1;
    while (!q.empty() && index < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Process left child
        if (nodes[index] != "null") {
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        }
        index++;

        // Process right child
        if (index < nodes.size() && nodes[index] != "null") {
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        }
        index++;
    }

    return root;
}

// Function to calculate the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    string input;
    cout << "Enter the level-order traversal of the binary tree (use 'null' for empty nodes): ";
    getline(cin, input);

    // Parse input string into a vector of strings
    vector<string> nodes;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ' ')) {
        nodes.push_back(token);
    }

    // Build the binary tree from the parsed nodes
    TreeNode* root = buildTree(nodes);

    // Calculate and output the maximum depth of the binary tree
    int depth = maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}

