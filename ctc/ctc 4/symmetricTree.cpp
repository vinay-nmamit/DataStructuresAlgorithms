#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function to build a binary tree from serialized input
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

        if (nodes[index] != "null") {
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        }
        index++;

        if (index < nodes.size() && nodes[index] != "null") {
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        }
        index++;
    }

    return root;
}

// Function to check if a binary tree is symmetric (mirror image of itself)
bool isMirror(TreeNode* left, TreeNode* right) {
    // Base cases
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }

    // Check values and recursively check subtrees
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    // Check if tree is symmetric
    if (!root) {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main() {
    // Read input line containing serialized tree nodes
    string input;
    getline(cin, input);

    // Tokenize input string into node values
    vector<string> nodes;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ' ')) {
        nodes.push_back(token);
    }

    // Build the binary tree from serialized nodes
    TreeNode* root = buildTree(nodes);

    // Check if the tree is symmetric
    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
