#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to build a binary tree from user input (level-order traversal)
TreeNode* buildTreeFromInput() {
    string input;
    cout << "Enter the level-order traversal of the binary tree (use 'null' for empty nodes): ";
    getline(cin, input);

    if (input.empty() || input == "null") {
        return nullptr;
    }

    istringstream iss(input);
    string token;
    queue<TreeNode*> q;
    TreeNode* root = nullptr;

    // Read the root value
    if (getline(iss, token, ',')) {
        if (token != "null") {
            root = new TreeNode(stoi(token));
            q.push(root);
        }
    }

    while (!q.empty() && getline(iss, token, ',')) {
        TreeNode* curr = q.front();
        q.pop();

        // Read left child
        if (token != "null") {
            curr->left = new TreeNode(stoi(token));
            q.push(curr->left);
        }

        // Read right child
        if (getline(iss, token, ',') && token != "null") {
            curr->right = new TreeNode(stoi(token));
            q.push(curr->right);
        }
    }

    return root;
}

// Function to delete a binary tree and release memory
void deleteTree(TreeNode* root) {
    if (!root) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to count the number of good nodes in a binary tree
int countGoodNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int count = 0;
    dfs(root, root->val, count);
    return count;
}

// Helper DFS function to count good nodes recursively
void dfs(TreeNode* node, int curmax, int& count) {
    if (!node) {
        return;
    }

    if (node->val >= curmax) {
        count++;
        curmax = node->val;
    }

    dfs(node->left, curmax, count);
    dfs(node->right, curmax, count);
}

int main() {
    // Build the binary tree from user input
    TreeNode* root = buildTreeFromInput();

    if (!root) {
        cout << "Tree is empty." << endl;
        return 0;
    }

    // Count the number of good nodes in the tree
    int goodNodeCount = countGoodNodes(root);
    cout << "Number of good nodes in the tree: " << goodNodeCount << endl;

    // Clean up allocated memory by deleting the tree
    deleteTree(root);

    return 0;
}
