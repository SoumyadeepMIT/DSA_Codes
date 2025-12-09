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

vector<int> leftView(Node *root) {
    // code here
    queue<Node*> qu;
    qu.push(root);
    vector<int> res;
    while(!qu.empty()){
        int sz = qu.size();
        for(int i=0;i<sz;i++){
            Node* nod = qu.front();
            qu.pop();
            if(i==0) res.push_back(nod->data);
            if(nod->left) qu.push(nod->left);
            if(nod->right) qu.push(nod->right);
        }
    }
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);

    vector<int> res = leftView(root);
    for (int node : res)
        cout << node << " ";
}