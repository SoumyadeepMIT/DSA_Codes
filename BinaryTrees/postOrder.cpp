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

void postorderRecur(Node* root){
    if(!root) return;
    postorderRecur(root->left);
    postorderRecur(root->right);
    cout<<root->data<<" ";
}

void postorderIter(Node* root){
    stack<Node* >st;
    stack<int> out;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        out.push(curr->data);
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
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
    postorderRecur(root);
    cout<<endl;
    postorderIter(root);
    return 0;
}