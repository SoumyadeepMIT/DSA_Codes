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
int countPairs(Node* root1, Node* root2, int x) {
    // code here
    vector<int> in1,in2;
    inorder(root1, in1);
    inorder(root2, in2);
    int res = 0;
    int i=0, j=in2.size()-1;
    while(i<in1.size() && j>=0){
        if(in1[i] + in2[j] == x){
            i++;
            j--;
            res++;
        }
        else if(in1[i] + in2[j] <x) i++;
        else j--;
    }
    return res;
}
int main() {
    
    // BST1
    //    2
    //  /  \
    // 1   3
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    
    // BST2
    //    5
    //  /  \
    // 4   6
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);
    
    int x = 6;
    cout << countPairs(root1, root2, x);

    return 0;
}