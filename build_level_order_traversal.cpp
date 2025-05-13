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

        if (leftData != -1) {  // ✅ FIXED: Should only create node if data is not -1
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1) {  // ✅ FIXED: Should only create node if data is not -1
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
}

int main() {
    node* root = NULL;
    buildFromLevelOrder(root);

    levelOrderTraversal(root);
    return 0;
}
