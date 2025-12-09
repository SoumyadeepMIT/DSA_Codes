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

int help(Node* root, unordered_map<Node*, int> &dp){
    if(!root) return 0;
    if(dp.find(root)!=dp.end()) return dp[root];
    int inc = root->data;
    int exc = 0;
    if(root->left){
        inc += help(root->left->left, dp) + help(root->left->right, dp);
    }
    if(root->right){
        inc += help(root->right->left, dp) + help(root->right->right, dp);
    }
    exc = help(root->left, dp) + help(root->right, dp);
    dp[root] = max(inc, exc);
    return dp[root];
}
int getMaxSum(Node *root) {
    // code here
    unordered_map<Node*, int> dp;
    return help(root, dp);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    cout << getMaxSum(root) << endl;
    return 0;
}