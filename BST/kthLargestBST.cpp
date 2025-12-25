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
int help(Node* root, int& c, int k){
    if(!root) return -1;
    int right = help(root->right, c,k);
    if(right!=-1) return right;
    c++;
    if(c==k) return root->data;
    return help(root->left, c, k);
}
int kthLargest(Node *root, int k) {
    // Your code here
    int c = 0;
    return help(root, c, k);
}
int main() {
    
    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12  
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    int k = 3;
    
    cout << kthLargest(root, k) << endl;
    
    return 0;
}