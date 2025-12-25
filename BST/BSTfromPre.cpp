#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* help(int pre[], int size, int& i,int minv, int maxv){
    if(i==size) return NULL;
    if(pre[i]<minv || pre[i]>maxv) return NULL;
    Node* root = newNode(pre[i++]);
    root->left = help(pre, size, i,minv,root->data);
    root->right = help(pre, size, i, root->data, maxv);
    return root;
}
Node* Bst(int pre[], int size) {
    // code here
    int i = 0;
    return help(pre, size, i, INT_MIN, INT_MAX);
}
void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Driver code
int main() {
    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre) / sizeof(pre[0]);

    struct Node* root = Bst(pre, n);
    printInorder(root);
    return 0;
}