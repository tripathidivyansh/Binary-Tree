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

// Function to build the binary tree from user input
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

// Function to print level order traversal using NULL markers
void levelOrderTraversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Level separator

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    root = buildTree();

    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Print the level order traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}
