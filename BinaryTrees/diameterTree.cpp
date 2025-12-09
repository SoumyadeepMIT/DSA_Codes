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

int md = 0;
int calc(Node* root) {
    // code here
    if(!root) return 0;
    int lh = calc(root->left);
    int rh = calc(root->right);
    md = max(md, lh+rh);
    return 1+max(lh,rh);
}
int diameter(Node* root){
    calc(root);
    return md;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);

    cout << diameter(root) << endl;

    return 0;
}