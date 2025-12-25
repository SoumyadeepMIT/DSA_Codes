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
int getCount(Node *root, int l, int h) {
    // your code here
    if(!root) return 0;
    if(root->data>=l && root->data<=h)
        return 1 + getCount(root->left,l,h) + getCount(root->right, l, h);
    if(root->data<l)
        return getCount(root->right, l, h);
    return getCount(root->left, l, h);
}
int main() {
    
    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50 
    //     /   /  \    
    //    1   40  100
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;
    
    cout << getCount(root, l, h) << endl;
    
    return 0;
}