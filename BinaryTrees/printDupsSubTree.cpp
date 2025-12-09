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
string help(Node* root, unordered_map<string,int>& um,vector<Node*> &res){
    if(!root) return "N";
    string left = help(root->left, um, res);
    string right = help(root->right, um, res);
    string dat = to_string(root->data);
    string cur = "(" + left + ")" + dat + "(" + right + ")";
    um[cur]++;
    if(um[cur]==2) res.push_back(root);
    return cur;
}
vector<Node*> printAllDups(Node* root) {
    // Code here
    vector<Node*> res;
    unordered_map<string, int> um;
    help(root, um, res);
    return res;
}
void preOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(4);
    
    vector<Node*> ans = printAllDups(root);
    
    for (Node* node: ans) {
        preOrder(node);
        cout << endl;
    }
    
    return 0;
}