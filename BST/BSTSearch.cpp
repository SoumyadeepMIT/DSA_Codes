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
class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root) return false;
        if(key<root->data) return search(root->left, key);
        if(key == root->data) return true;
        return search(root->right, key);
    }
};

int main(){
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    Solution s;
    if(s.search(root, key)) cout<<"Found";
    else cout<<"Not Found";
    return 0;
}