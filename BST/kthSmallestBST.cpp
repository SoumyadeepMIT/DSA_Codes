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
int help(Node* root, int &c,int k){
    if(!root) return -1;
    int l = help(root->left, c, k);
    if(l!=-1) return l;
    c++;
    if(c==k) return root->data;
    return help(root->right, c, k);
}
int kthSmallest(Node *root, int k) {
    // code here
    int c = 0;
    return help(root, c, k);
}
int main() {
    
    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int k = 3;

    cout << kthSmallest(root, k) << endl;
    return 0;
}