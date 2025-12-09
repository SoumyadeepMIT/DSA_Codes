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
Node* lca(Node* root, int n1, int n2) {
    //  code here
    if(!root) return NULL;
    if(root->data == n1 || root->data == n2) return root;
    Node* left = lca(root->left, n1,n2);
    Node* right = lca(root->right, n1, n2);
    if(left && right) return root;
    return left?left:right;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    Node* ans = lca(root, 7, 8);
   
    cout<<ans->data;

    return 0;
}