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

// Reverse Level Order Traversal
void levelorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        // Push right first, then left so that left is processed first when reversed
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Print the reversed level order
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    node* root = NULL;
    root = buildTree();

    cout << "Reverse Level Order Traversal: ";
    levelorderTraversal(root);

    return 0;
}
