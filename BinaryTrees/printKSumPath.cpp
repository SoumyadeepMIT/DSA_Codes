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
void help(Node* root, int k, int& res, vector<int>& path){
    if(!root) return;
    path.push_back(root->data);
    help(root->left, k, res, path);
    help(root->right, k, res, path);
    int sum = 0;
    for(int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum == k) res++;
    }
    path.pop_back();
}
int noWays(Node* root, int k) {
    // Write your code here.
    int res = 0;
    vector<int> path;
    help(root, k, res, path);
    return res;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    cout<<noWays(root, k);
    return 0;
}