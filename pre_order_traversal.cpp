#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root = NULL;
    root = buildTree();

    preorder(root);

}