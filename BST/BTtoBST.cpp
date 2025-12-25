#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void inorder(Node* root, vector<int>& res){
    if(!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
void construct(Node* root, vector<int> in, int& i){
    if(!root) return;
    construct(root->left, in, i);
    root->data = in[i++];
    construct(root->right, in, i);
}
Node *binaryTreeToBST(Node *root) {
    // Your code goes here
    vector<int> res;
    inorder(root, res);
    sort(res.begin(), res.end());
    int i = 0;
    construct(root, res, i);
    return root;
}
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    
    // Creating the tree
    //         10
    //        /  \
    //       2    7
    //      / \
    //     8   4
    Node* root = new Node(10);   
    root->left = new Node(2);    
    root->right = new Node(7);   
    root->left->left = new Node(8);  
    root->left->right = new Node(4);
    
    Node* ans = binaryTreeToBST(root);
    printInorder(ans);

    return 0;
}