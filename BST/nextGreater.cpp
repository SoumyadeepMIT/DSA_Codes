#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
class Solution {
  public:
    Node* insertSucc(Node* root, int val, int& suc){
        if(!root){
            Node* node = new Node(val);
            return node;
        }
        if(val>=root->data){
            root->right = insertSucc(root->right, val, suc);
        }
        else{
            suc = root->data;
            root->left = insertSucc(root->left, val, suc);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        vector<int> res(arr.size(), -1);
        for(int i = arr.size()-1;i>=0;i--){
            int suc = -1;
            root = insertSucc(root, arr[i], suc);
            res[i] = suc;
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> arr = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    vector<int> res = s.findLeastGreater(arr, arr.size());
    for(int n: res) cout<<n<<" ";
    return 0;
}