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

void help(Node* root, int l,int s,int &res,int &len){
    if(!root) return;
    if(!root->left && !root->right){
        if(l>len){
            len = l;
            res = root->data + s;
        }
        else if(l == len){
            res = max(res, root->data + s);
        }
        return;
    }
    help(root->left, l+1, s+root->data, res, len);
    help(root->right, l+1, s+root->data, res, len);
}
int sumOfLongRootToLeafPath(Node *root) {
    // code here
    int res = 0, len = 0;
    help(root, 0, 0, res, len);
    return res;
}
int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    cout << sumOfLongRootToLeafPath(root);

    return 0;
}