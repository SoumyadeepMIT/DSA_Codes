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
Node* getSucc(Node* curr){
    curr = curr->right;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}
Node* delNode(Node* root, int x) {
    // code here
    if(!root) return NULL;
    if(x<root->data) root->left = delNode(root->left, x);
    else if(x> root->data) root->right = delNode(root->right, x);
    else{
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = getSucc(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    int x = 15;
    root = delNode(root, x);
    return 0;
}