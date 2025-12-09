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
bool isIsomorphic(Node *root1, Node *root2) {
    // add code here.
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data!= root2->data) return false;
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) 
    || (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

int main(){
    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       / \
    //      7   8
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      3   2
    //     /   / \
    //    6   4   5
    //           / \
    //          8   7
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->left = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    if (isIsomorphic(root1, root2)) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }

    return 0;
}