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

// Build the binary tree from level-order input
void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    int data;
    cin >> data;

    if (data == -1) {
        root = NULL;
        return;
    } 

    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// Height function (your logic)
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;

    return ans;
}

// Diameter function (your logic)
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}

int main() {
    Node* root = NULL;
    cout << "Enter tree in level order (-1 for NULL): ";
    buildFromLevelOrder(root);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diameter of the tree: " << diameter(root) << endl;

    return 0;
}
