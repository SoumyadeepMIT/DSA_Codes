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

vector<int> zigZagTraversal(Node* root) {
    // code here
    int lv = 0;
    queue<Node* > qu;
    qu.push(root);
    vector<int> res;
    while(!qu.empty()){
        int sz = qu.size();
        vector<int> temp;
        lv++;
        for(int i=0;i<sz;i++){
            Node* nod = qu.front();
            qu.pop();
            temp.push_back(nod->data);
            if(nod->left) qu.push(nod->left);
            if(nod->right) qu.push(nod->right);
        }
        if(lv%2!=0){
            for(int i=0;i<sz;i++) res.push_back(temp[i]);
        }
        else{
            for(int i=sz-1;i>=0;i--) res.push_back(temp[i]);
        }
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

    vector<int> result = zigZagTraversal(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}