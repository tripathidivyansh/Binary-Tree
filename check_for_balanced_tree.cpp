#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// Build binary tree from preorder input
Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Function to compute height of tree
int height(Node* root) {
    if (root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

// Function to check if tree is balanced (O(n^2) approach)
bool isBalanced(Node* root) {
    if (root == NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL): ";
    Node* root = buildTree();

    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}
