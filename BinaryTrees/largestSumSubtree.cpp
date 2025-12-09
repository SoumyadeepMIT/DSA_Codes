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

int help(Node* root, int &res){
    if(!root) return 0;
    if(!root->left && !root->right){
        res = max(res, root->data);
        return root->data;
    };
    int ls = help(root->left, res);
    int rs = help(root->right, res);
    res = max(res, ls+rs+root->data);
    return ls+rs+root->data;
}
int findLargestSubtreeSum(Node* root) {
    // Write your code here
    int res = INT_MIN;
    help(root, res);
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}