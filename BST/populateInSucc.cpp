#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
void populateNextRecur(Node *p, Node **next_ref) {
    if (p) {
        populateNextRecur(p->right, next_ref);
        p->next = *next_ref;
        *next_ref = p;
        populateNextRecur(p->left, next_ref);
    }
}

void populateNext(Node *root) {
    Node *next = NULL;
    populateNextRecur(root, &next);
}
int main()
{

    /* Constructed binary tree is
            10
            / \
        8 12
        /
    3
    */
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    Node* ptr = root->left->left;
    while (ptr) {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }

    return 0;
}