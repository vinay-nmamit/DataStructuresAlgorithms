#include <bits/stdc++.h> // Include all standard library components

using namespace std; // Use the standard namespace

// Define a TreeNode structure to represent a node in a binary tree
struct TreeNode {
    int val; // Value of the node
    TreeNode* left; // Pointer to the left child node
    TreeNode* right; // Pointer to the right child node

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value initialization
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and child nodes initialization
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function to build a binary tree from a vector of strings
TreeNode* buildTree(const vector<string>& nodes) {
    // Return nullptr if the input vector is empty or the first element is "null"
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    // Create a root node with the first element's value
    TreeNode* root = new TreeNode(stoi(nodes[0]));

    // Create a queue to store the nodes for breadth-first traversal
    queue<TreeNode*> q;
    q.push(root);

    // Initialize the index to traverse the input vector
    size_t index = 1;

    // Loop until the queue is empty and the index is within the vector's bounds
    while (!q.empty() && index < nodes.size()) {
        // Get the current node from the queue
        TreeNode* current = q.front();
        q.pop();

        // If the current node's left child is not "null", create a new node and add it to the queue
        if (nodes[index]!= "null") {
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        }
        index++;

        // If the current node's right child is not "null" and the index is within the vector's bounds,
        // create a new node and add it to the queue
        if (nodes[index]!= "null" && index < nodes.size()) {
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        }
        index++;
    }

    // Return the root node
    return root;
}

// Function to check if two binary trees are mirrors of each other
bool areMirrors(TreeNode* p, TreeNode* q) {
    // If both nodes are null, return true
    if (!p &&!q) return true;

    // If one node is null or the values are not equal, return false
    if (!p ||!q || p->val!= q->val) return false;

    // Recursively check the left and right subtrees
    return areMirrors(p->left, q->right) && areMirrors(p->right, q->left);
}

// Function to check if two binary trees are mirrors of each other
bool areMirrortrees(TreeNode* p, TreeNode* q) {
    // Call the areMirrors function
    return areMirrors(p, q);
}

// Main function
int main() {
    // Get input strings for the two binary trees
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);

    // Tokenize the input strings
    string token;
    stringstream ss1(input1);
    stringstream ss2(input2);

    // Create vectors to store the nodes
    vector<string> nodes1;
    vector<string> nodes2;

    // Loop to tokenize the input strings and store the nodes
    while (getline(ss1, token, ' ')) {
        nodes1.push_back(token);
    }
    while (getline(ss2, token, ' ')) {
        nodes2.push_back(token);
    }

    // Build the binary trees
    TreeNode *root1 = buildTree(nodes1);
    TreeNode *root2 = buildTree(nodes2);

    // Check if the binary trees are mirrors of each other
    if (areMirrortrees(root1, root2)) {
        cout << "mirror trees" << endl;
    } else {
        cout << "not mirror trees" << endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}
