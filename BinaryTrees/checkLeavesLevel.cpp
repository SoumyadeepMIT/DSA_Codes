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

bool help(Node* root, int l, int &lv){
    if(!root) return true;
    if(!root->left && !root->right){
        if(lv==-1){
            lv = l;
            return true;
        }
        return (lv == l);
    }
    return (help(root->left,l+1, lv) && help(root->right, l+1, lv));
}
bool check(Node *root) {
    // Your code here
    int lv = -1;
    return help(root, 0,lv);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int result = check(root);
    if (result)
        cout << "All leaf nodes are at same level\n";
    else
        cout << "Leaf nodes not at same level\n";
    return 0;
}