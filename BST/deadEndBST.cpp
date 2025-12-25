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
    if(!root) return false;
    if(!root->left && !root->right && minv==maxv) return true;
    return check(root->left, minv, root->data-1) || check(root->right,root->data+1,maxv);
}
bool isDeadEnd(Node *root) {
    // Code here
    return check(root, 1, INT_MAX);
}
int main() {
    
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    if (isDeadEnd(root)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}