#include <bits/stdc++.h>
using namespace std;

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

node* buildTree() {
    cout << "Enter the data: ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = buildTree();

    cout << "Enter data for right of " << data << endl;
    root->right = buildTree();

    return root;
}
void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    root = buildTree(); 
    cout << "Inorder traversal is: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inorder(root);
    return 0;
}
