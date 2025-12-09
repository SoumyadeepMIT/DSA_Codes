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

Node* help(vector<int> &inorder, vector<int> &preorder, unordered_map<int,int>& um,int &ind, int l, int r){
    if(l>r) return NULL;
    int v = preorder[ind];
    ind++;
    int i = um[v];
    Node* nod = new Node(v);
    nod->left = help(inorder, preorder, um, ind, l, i-1);
    nod->right = help(inorder, preorder, um, ind, i+1,r);
    return nod;
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    // code here
    unordered_map<int,int> um;
    int n = preorder.size();
    for(int i=0;i<n;i++){
        um[inorder[i]] = i;
    }
    int ind = 0;
    Node* root = help(inorder, preorder, um, ind, 0, n-1);
    return root;
}
int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}

void levelOrder(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    // function to get the height of tree
    int height = getHeight(root, 0);

    // printing the level order of tree
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        Node* node = top.first;
        int lvl = top.second;

        if (lvl > lastLevel) {
            cout << "\n";
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        
        if (node->data != -1) cout << node->data << " ";
        
        // printing null node
        else cout << "N ";

        // null node has no children
        if (node->data == -1) continue;

        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left, lvl + 1});

        if (node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl + 1});
    }
}


int main() {
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    levelOrder(root);

    return 0;
}