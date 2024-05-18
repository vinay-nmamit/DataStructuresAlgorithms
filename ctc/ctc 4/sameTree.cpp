#include <bits/stdc++.h>
using namespace std;

// Definition of a TreeNode structure, which contains an integer value and pointers to left and right child nodes
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right){}
};

// Function to check if two trees are identical, returning true if they are and false otherwise
bool isSametree(TreeNode *p, TreeNode *q) {
    // Initialize a flag variable to keep track of whether the trees are identical
    bool flag = true;

    // Perform preorder traversal of both trees, updating the flag
    preorder(p, q, flag);

    // Return the final value of the flag
    return flag;
}


// Recursive function to perform a preorder traversal of two trees, comparing their nodes and updating the flag variable
void preorder(TreeNode *p, TreeNode *q, bool &flag) {
    // Base case
    if (!p && !q) return;

    // Check if one node is null and the other is not, or their values differ
    if (!p || !q || p->val != q->val) {
        flag = false;
        return;
    }

    // Recursively check left and right subtrees
    preorder(p->left, q->left, flag);
    preorder(p->right, q->right, flag);
}


TreeNode* buildTree(const vector<string>& nodes){
    if(nodes.empty() || nodes[0] == "none") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    size_t index = 1;
    while(!q.empty() && index < nodes.size()){
        TreeNode* current = q.front();
        q.pop();

        if(nodes[index]!="none"){
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        } index++;

        if(index < nodes.size() && nodes[index] != "none"){
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        } index++;
    }
    return root;
}

int main() {
    string input1, input2;
    getline(cin, input1); // First tree input
    getline(cin, input2); // Second tree input

    vector<string> nodes1, nodes2;
    stringstream ss1(input1);
    stringstream ss2(input2);

    string token;
    while (getline(ss1, token, ' ')) {
        nodes1.push_back(token);
    }
    while (getline(ss2, token, ' ')) {
        nodes2.push_back(token);
    }

    TreeNode *root1 = buildTree(nodes1);
    TreeNode *root2 = buildTree(nodes2);

    bool areSame = isSametree(root1, root2);

    if (areSame) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}
