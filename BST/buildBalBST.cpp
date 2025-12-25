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
void inorder(Node* root, vector<int>& in){
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
Node* build(vector<int>& in, int st, int end){
    if(st>end) return NULL;
    int mid = (st + end)/2;
    Node* root = new Node(in[mid]);
    root->left = build(in,st,mid-1);
    root->right = build(in, mid+1, end);
    return root;
}
Node* balanceBST(Node* root) {
    // Code here
    vector<int> in;
    inorder(root, in);
    return build(in, 0,in.size()-1);
}
// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

int main() {
    
    // Constructing an unbalanced BST
    //        4
    //       / \
    //      3   5
    //     /     \
    //    2       6
    //   /		   \
    //  1		    7

    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(6);
  	root->right->right->right = new Node(7);

    Node* balancedRoot = balanceBST(root);
    printLevelOrder(balancedRoot);

    return 0;
}
