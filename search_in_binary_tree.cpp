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

// Function to insert a node in BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to search a value in BST
bool search(Node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;

    if (x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes to insert in BST: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter value to search: ";
    cin >> x;

    if (search(root, x)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
