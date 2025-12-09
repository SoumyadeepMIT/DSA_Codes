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

Node* preOrder(int &i, string &s) {
    
    if (i>=s.length() || s[i]==')') return nullptr;

    string num = "";
    while (i<s.length() && s[i]!='(' && s[i]!=')') {
        num += s[i++];
    } 
    
    Node* root = new Node(stoi(num));
    if (i<s.length() && s[i]=='(') {
        i++;
        root->left = preOrder(i, s);
        i++;
    }
    
    if (i<s.length() && s[i]=='(') {
        i++;
        root->right = preOrder(i, s);
        i++;
    }
    return root;
}
Node *treeFromString(string s){
    
    int i = 0;
    return preOrder(i, s);
}

void levelOrder(Node *root) {
    if (root == nullptr) {
          cout << "N ";
          return ;
    }

    queue<Node*> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        cout << (curr->data) <<  " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}

int main() {
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str);
    levelOrder(root);
}