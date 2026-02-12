#include <bits/stdc++.h> 
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
int totalNodes(Node* tree){
    if(!tree) return 0;
    return 1+totalNodes(tree->left) + totalNodes(tree->right);
}
bool heapCheck(Node* tree, int ind, int tot){
    if(!tree) return true;
    if(ind>=tot) return false;
    if(tree->left && tree->data < tree->left->data) return false;
    if(tree->right && tree->data < tree->right->data) return false;
    return heapCheck(tree->left, 2*ind+1, tot) && heapCheck(tree->right, 2*ind+2, tot);
}
bool isHeap(Node* tree) {
    // code here
    int tot=totalNodes(tree);
    return heapCheck(tree, 0, tot);
}
int main(){
    Node *root = new Node(97);
    root->left = new Node(46);
    root->right = new Node(37);
    root->left->left = new Node(12);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(31);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(9);
    if(isHeap(root)) cout<<"It's a max heap";
    else cout<<"Its not a max heap";
    return 0;
}
