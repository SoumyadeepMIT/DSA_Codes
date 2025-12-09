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

bool isLeaf(Node* root){
    if(!root->left && !root->right) return true;
    return false;
}
void lb(Node* root,vector<int>& res){
    if(!root || isLeaf(root)) return;
    res.push_back(root->data);
    if(root->left) lb(root->left,res);
    else if(root->right) lb(root->right, res);
}
void rb(Node* root, vector<int>& res){
    if(!root || isLeaf(root)) return;
    if(root->right) rb(root->right, res);
    else if(root->left) rb(root->left, res);
    res.push_back(root->data);
}
void leaf(Node* root, vector<int>& res){
    if(!root) return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    leaf(root->left, res);
    leaf(root->right, res);
}
vector<int> boundaryTraversal(Node *root) {
    // code here
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    lb(root->left, res);
    leaf(root, res);
    rb(root->right, res);
    return res;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);


    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}