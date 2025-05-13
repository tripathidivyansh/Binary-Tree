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

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    int data;
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

        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Function to compute height in terms of edges
int height(node* root) {
    if (root == NULL) return -1; // ✅ height in edges
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

int main() {
    node* root = NULL;
    cout << "Enter level order data (-1 for NULL): ";
    buildFromLevelOrder(root);

    int h = height(root);
    cout << "Height of the tree (in edges): " << h << endl;

    return 0;
}
