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

vector<int> reverseLevelOrder(Node *root) {
    // code here
    queue<Node*> qu;
    stack<int> st;
    vector<int> res;
    qu.push(root);
    while(!qu.empty()){
        while(!qu.empty()){
            Node* nod = qu.front();
            qu.pop();
            st.push(nod->data);
            if(nod->right) qu.push(nod->right);
            if(nod->left) qu.push(nod->left);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
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

    vector<int> res = reverseLevelOrder(root);

    for (int n: res) {
        cout<<n<<" ";
    }

    return 0;    
}