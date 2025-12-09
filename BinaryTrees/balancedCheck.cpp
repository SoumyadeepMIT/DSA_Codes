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

int balanced(Node* root){
    if(!root) return 0;
    int lh = balanced(root->left);
    int rh = balanced(root->right);
    if(lh == -1 || rh == -1 || abs(lh-rh)>1) return -1;
    return max(lh,rh) + 1;
}
bool isBalanced(Node* root) {
    // code here
    return (balanced(root)>0);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << (isBalanced(root) ? "true" : "false");
    return 0;
}