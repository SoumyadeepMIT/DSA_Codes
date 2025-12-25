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
Node* LCA(Node* root, Node* n1, Node* n2) {
    // code here
    if(!root) return NULL;
    if(n1->data<root->data && n2->data<root->data){
        return LCA(root->left, n1,n2);
    }
    if(n1->data>root->data && n2->data> root->data)
        return LCA(root->right, n1,n2);
    return root;
}
int main(){
    // Representation of input BST:
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

    // Node 4
    Node* n1 = root->left->left; 
    
    // Node 14
    Node* n2 = root->left->right->right; 

    Node* res = LCA(root, n1, n2);
    cout << res->data << endl;

    return 0;
}