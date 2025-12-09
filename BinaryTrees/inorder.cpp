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

void inorderRecur(Node* root){
    if(!root) return;
    inorderRecur(root->left);
    cout<<root->data<<" ";
    inorderRecur(root->right);
}

void inorderIter(Node* root){
    stack<Node* > st;
    Node* curr = root;
    while(!st.empty() || curr){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    inorderRecur(root);
    cout<<endl;
    inorderIter(root);
    return 0;
}