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

void help(Node* root, Node* &prev, Node* &head){
    if(!root) return;
    help(root->left, prev, head);
    if(prev==NULL) head = root;
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    help(root->right, prev, head);
}
Node* bToDLL(Node* root) {
    // code here
    Node* head = NULL;
    Node* prev = NULL;
    help(root, prev, head);
    return head;
}
void printList(Node* head) {
    Node* curr = head;
    
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    
    // Create a hard coded binary tree
    //          10
    //         /  \
    //       12    15    
    //      / \    /
    //     25 30  36
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node* head = bToDLL(root);

    printList(head);

    return 0;
}