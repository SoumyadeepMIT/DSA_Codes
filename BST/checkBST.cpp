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

bool check(Node* root, int minv, int maxv){
    if(!root) return true;
    if(root->data<minv || root->data>maxv) return false;
    return check(root->left, minv,root->data) && check(root->right, root->data, maxv);
}
bool isBST(Node* root) {
    // code here
    return check(root,INT_MIN,INT_MAX);
}
int main(){
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    return 0;
}