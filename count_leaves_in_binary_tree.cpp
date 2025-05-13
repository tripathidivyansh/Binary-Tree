#include <bits/stdc++.h>
using namespace std;

// Node structure
class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build tree using level order input
void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1) {
        root = NULL;
        return;
    }

    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Function to count leaf nodes
int countLeafNodes(node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    node* root = NULL;

    // Build the tree
    buildFromLevelOrder(root);

    // Count and display leaf nodes
    int leafCount = countLeafNodes(root);
    cout << "Total number of leaf nodes: " << leafCount << endl;

    return 0;
}
