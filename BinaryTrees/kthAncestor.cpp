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
int help(Node *root, int tar, int& k, int& res){
    if(!root) return -1;
    if(root->data == tar || help(root->left,tar,k,res)!=-1 || help(root->right,tar,k,res)!=-1){
        if(k>0) k--;
        else if(k==0){
            res = root->data;
            return -1;
        }
        return root->data;
    }
    return -1;
}
int findKthAncestor(Node *root, int targetNodeVal, int k) {
    // Write your code here.
    int res = -1;
    help(root, targetNodeVal, k, res);
    return res;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    int parent = findKthAncestor(root,node,k);
    
    cout<<parent;
    
    return 0;
}