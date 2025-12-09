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

void printInorder(Node* Node) 
{ 
    if (Node == NULL) 
        return; 
    printInorder(Node->left); 
    cout<<" "<<Node->data; 
    printInorder(Node->right); 
} 

int toSum(Node* &node){
    if(!node) return 0;
    int ls = toSum(node->left);
    int rs = toSum(node->right);
    int v = node->data;
    node->data = ls + rs;
    return v + ls + rs;
}
void toSumTree(Node *node) {
    // Your code here
    toSum(node);
}
int main() 
{ 
    Node *root = NULL; 
    int x; 
    
    /* Constructing tree given in the above figure */
    root = new Node(10); 
    root->left = new Node(-2); 
    root->right = new Node(6); 
    root->left->left = new Node(8); 
    root->left->right = new Node(-4); 
    root->right->left = new Node(7); 
    root->right->right = new Node(5); 
    
    toSumTree(root); 
    
    // Print inorder traversal of the converted
    // tree to test result of toSumTree() 
    cout<<"Inorder Traversal of the resultant tree is: \n"; 
    printInorder(root); 
    return 0; 
} 