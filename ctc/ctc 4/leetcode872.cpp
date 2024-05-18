#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Utility function to trim whitespace from a string
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}

// Function to build a binary tree from a string representing its level-order traversal
TreeNode* buildTreeFromString(const string& data) {
    if (data.empty() || data == "null") return nullptr;

    vector<string> nodes;
    istringstream iss(data);
    string token;
    while (getline(iss, token, ',')) {
        nodes.push_back(trim(token));
    }

    if (nodes.empty()) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Depth-first search to collect leaf node values
void dfs(TreeNode* root, vector<int>& leaves) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        leaves.push_back(root->val);
        return;
    }
    dfs(root->left, leaves);
    dfs(root->right, leaves);
}

// Function to check if two binary trees have identical leaf sequences
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    dfs(root1, leaves1);
    dfs(root2, leaves2);
    return leaves1 == leaves2;
}

int main() {
    string input1, input2;

    cout << "Enter the level-order traversal of the first tree (use 'null' for null values): ";
    getline(cin, input1);

    cout << "Enter the level-order traversal of the second tree (use 'null' for null values): ";
    getline(cin, input2);

    TreeNode* root1 = buildTreeFromString(input1);
    TreeNode* root2 = buildTreeFromString(input2);

    if (leafSimilar(root1, root2)) {
        cout << "The leaf sequences of the two trees are identical." << endl;
    } else {
        cout << "The leaf sequences of the two trees are not identical." << endl;
    }

    // Clean up memory (optional if not in a reusable context)
    // This part would be relevant in a scenario where you need to release the allocated memory.
    // Usually handled by system at the end of a process, and often relevant in large systems.
    // would it be relevant in your code too?
    delete root1;
    delete root2;
    
    return 0;
}
