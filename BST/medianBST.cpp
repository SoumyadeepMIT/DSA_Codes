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
void inorder(Node* root, vector<int>& in){
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int findMedian(Node* root) {
    // Code here
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    if(n%2==0) return in[n/2-1];
    return in[(n+1)/2-1];
}
int main() {
    // Create BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14 
    
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << findMedian(root) << endl;
    return 0;
}