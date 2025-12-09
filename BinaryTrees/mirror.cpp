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

Node* invertTree(Node* root){
    if(!root) return NULL;
    Node* lt = invertTree(root->left);
    Node* rt = invertTree(root->right);
    root->left = rt;
    root->right = lt;
    return root;
}

void lot(Node* root){
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        while(!qu.empty()){
            Node* nod = qu.front();
            qu.pop();
            cout<<nod->data<<" ";
            if(nod->left) qu.push(nod->left);
            if(nod->right) qu.push(nod->right);
        }
        cout<<endl;
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    invertTree(root);
    lot(root);
    return 0;
}