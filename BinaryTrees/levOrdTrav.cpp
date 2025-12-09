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

vector<vector<int>> levelOrder(Node *root) {
    // code here
    queue<Node*> qu;
    qu.push(root);
    vector<vector<int>> res;
    while(!qu.empty()){
        vector<int> temp;
        queue<Node* > nq;
        while(!qu.empty()){
            Node* nod = qu.front();
            qu.pop();
            temp.push_back(nod->data);
            if(nod->left) nq.push(nod->left);
            if(nod->right) nq.push(nod->right);
        }
        qu = nq;
        res.push_back(temp);
    }
    return res;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl; 
    }

    return 0;
}