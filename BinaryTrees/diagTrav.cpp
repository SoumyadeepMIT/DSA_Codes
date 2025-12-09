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

void help(Node* root, unordered_map<int, vector<int>> &ld, int lv){
    if(!root) return;
    ld[lv].push_back(root->data);
    help(root->left, ld, lv+1);
    help(root->right, ld, lv);
}
vector<int> diagonal(Node *root) {
    // code here
    vector<int> res;
    unordered_map<int,vector<int>> ld;
    help(root, ld, 0);
    int lv = 0;
    while(ld.find(lv)!=ld.end()){
        for(int n:ld[lv]) res.push_back(n);
        lv++;
    }
    return res;
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    vector<int> ans = diagonal(root);
    for(int n:ans) cout<<n<<" ";
}