#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
pair<bool, int> isSumTreeFast(Node* root) {
    if (root == NULL)
        return {true, 0};

    if (root->left == NULL && root->right == NULL)
        return {true, root->data};

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool isCurrentSumTree = (root->data == left.second + right.second);

    if (left.first && right.first && isCurrentSumTree) {
        return {true, root->data * 2};
    }

    return {false, 0};
}

bool isSumTree(Node* root) {
    return isSumTreeFast(root).first;
}

int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL): ";
    Node* root = buildTree();

    if (isSumTree(root)) {
        cout << "The tree is a Sum Tree." << endl;
    } else {
        cout << "The tree is NOT a Sum Tree." << endl;
    }

    return 0;
}
