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

Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1) return NULL;

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;

    if (root1 == NULL || root2 == NULL) return false;

    if (root1->data != root2->data) return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

int main() {
    cout << "Enter nodes for first tree (use -1 for NULL):" << endl;
    Node* root1 = buildTree();

    cout << "Enter nodes for second tree (use -1 for NULL):" << endl;
    Node* root2 = buildTree();

    if (isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are NOT identical." << endl;
    }

    return 0;
}
