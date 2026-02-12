#include <bits/stdc++.h> 
using namespace std;
class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};
void inorder(BinaryTreeNode* root, vector<int>& inord){
	if(!root) return;
	inorder(root->left, inord);
	inord.push_back(root->data);
	inorder(root->right, inord);
	return;
}
void preOrdFill(BinaryTreeNode* root, int& ind, vector<int>& inord){
	if(!root) return;
	root->data = inord[ind++];
	preOrdFill(root->left, ind, inord);
	preOrdFill(root->right, ind, inord);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> inord;
	inorder(root, inord);
	int ind=0;
	preOrdFill(root, ind, inord);
	return root;
}
void preorderPrint(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);
    root = convertBST(root);
    preorderPrint(root);
    return 0;
}