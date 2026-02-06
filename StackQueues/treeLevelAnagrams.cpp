#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool areAnagrams(Node *root1, Node *root2) {
    queue<Node*> qu1;
    queue<Node*> qu2;
    
    qu1.push(root1);
    qu2.push(root2);
    while(1){
        int n1 = qu1.size();
        int n2 = qu2.size();
        vector<int> lv1;
        vector<int> lv2;
        if(n1!=n2) return false;
        if(n1==0) break;
        for(int i=0;i<n1;i++){
            Node* nod1 = qu1.front();
            Node* nod2 = qu2.front();
            lv1.push_back(nod1->data);
            lv2.push_back(nod2->data);
            qu1.pop();
            qu2.pop();
            if(nod1->left){
                qu1.push(nod1->left);
            }
            if(nod1->right){
                qu1.push(nod1->right);
            }
            if(nod2->left){
                qu2.push(nod2->left);
            }
            if(nod2->right){
                qu2.push(nod2->right);
            }
        }
        sort(lv1.begin(), lv1.end());
        sort(lv2.begin(), lv2.end());
        if(lv1!=lv2) return false;
    }
    return true;
}
int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if(areAnagrams(root1, root2)){
        cout<<"Yes, they are anagrams at all levels."<<endl;
    }
    else{
        cout<<"No, they are not anagrams at all levels."<<endl;
    }
    return 0;
}