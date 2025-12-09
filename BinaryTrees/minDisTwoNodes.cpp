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
Node* lca(Node* root, int a,int b){
    if(!root) return NULL;
    if(root->data == a || root->data == b) return root;
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    if(left && right) return root;
    return left?left:right;
}
int dist(Node* root, int n, int c){
    if(!root) return -1;
    if(root->data == n) return c;
    int lc = dist(root->left, n,c+1);
    if(lc!=-1) return lc;
    return dist(root->right,n,c+1);
}
int findDist(Node* root, int a, int b) {
    // Your code here
    Node* lc = lca(root, a, b);
    int dl = dist(root, lc->data, 0);
    int d1 = dist(root, a, 0);
    int d2 = dist(root, b, 0);
    return d1 + d2 - 2*(dl);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a = 4, b = 7;
    cout << findDist(root, a, b) << endl;

    return 0;
}