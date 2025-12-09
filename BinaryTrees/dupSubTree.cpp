#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    char data;
    Node* left;
    Node* right;

    // Constructor
    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

string help(Node* root, unordered_set<string> &us,int &ans){
    if(!root) return "N";
    if(!root->left && !root->right) return to_string(root->data);
    string cur = "";
    cur += to_string(root->data);
    string left = help(root->left,us,ans);
    string right = help(root->right, us, ans);
    if(left!="" && right!=""){
        cur += "*";
        cur += left;
        cur += "*";
        cur += right;
    }
    else{
        return "";
    }
    if(us.find(cur)!=us.end()) ans = 1;
    else us.insert(cur);
    return "";
}
int dupSub(Node *root) {
    // code here
    int ans = 0;
    unordered_set<string> us;
    help(root, us, ans);
    return ans;
}

int main(){
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left = new Node('D');

    if (dupSub(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}