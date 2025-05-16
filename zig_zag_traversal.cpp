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

// Build tree from user input using preorder (-1 represents NULL)
Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// Zig-Zag Traversal Function
void zigZagTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            // Find position to fill node's data
            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        // Print current level
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

int main() {
    cout << "Enter nodes in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Zig-Zag Level Order Traversal:\n";
    zigZagTraversal(root);

    return 0;
}
