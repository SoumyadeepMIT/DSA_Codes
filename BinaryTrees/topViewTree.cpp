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

vector<int> topView(Node *root) {
        // code here
    queue<pair<Node*,int>> qu;
    unordered_map<int,int> um;
    int mind = 0;
    int maxd = 0;
    vector<int> res;
    qu.push({root, 0});
    while(!qu.empty()){
        pair<Node*, int> p = qu.front();
        qu.pop();
        mind = min(mind, p.second);
        maxd = max(maxd, p.second);
        if(um.find(p.second)==um.end()){
            um[p.second] = p.first->data;
        }
        if(p.first->left) qu.push({p.first->left, p.second -1});
        if(p.first->right) qu.push({p.first->right, p.second+1});
    }
    for(int i=mind;i<=maxd;i++){
        res.push_back(um[i]);
    }
    return res;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->left = new Node(90);
    root->right->right = new Node(100);

    vector<int> result = topView(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}