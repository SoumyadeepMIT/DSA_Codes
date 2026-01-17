#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
      Node* left;
      Node* right;
      int data;
      Node(int x){
          data = x;
          left = NULL;
          right = NULL;
      }
};
class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data>b->data;
        }
};
class Solution {
  public:
    void preorder(Node* root, vector<string>& res, string s){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            res.push_back(s);
            return;
        }
        preorder(root->left, res, s+'0');
        preorder(root->right, res, s+'1');
        return;
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for(int i=0;i<N;i++){
            Node* nod = new Node(f[i]);
            pq.push(nod);
        }
        Node* root = NULL;
        while(pq.size()>1){
            Node* l = pq.top();
            pq.pop();
            Node* r = pq.top();
            pq.pop();
            Node* nod = new Node(l->data + r->data);
            nod->left = l;
            nod->right = r;
            root = nod;
            pq.push(nod);
        }
        string s = "";
        vector<string> res;
        preorder(root, res, s);
        return res;
    }
};

int main() {
	string s = "abcdef";
	vector<int> freq = {5, 9, 12, 13, 16, 45};
	Solution sol;
    vector<string> ans = sol.huffmanCodes(s, freq, s.length());
	for (int i=0; i< ans.size(); i++) {
	    cout << ans[i] << " ";
	}
	
	return 0;
}