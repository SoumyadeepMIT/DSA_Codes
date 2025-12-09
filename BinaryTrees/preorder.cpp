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

void preorderRecur(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorderRecur(root->left);
    preorderRecur(root->right);
}

void preorderIter(Node* root){
    stack<Node *> st;
    st.push(root);
    Node* curr = root;
    while(!st.empty()){
        if(curr){
            cout<<curr->data<<" ";
            if(curr->right) st.push(curr->right);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();
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
    preorderRecur(root);
    cout<<endl;
    preorderIter(root);
    return 0;
}