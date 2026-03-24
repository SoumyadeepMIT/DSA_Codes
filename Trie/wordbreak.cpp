#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    TrieNode* child[26];
    bool isLeaf;
    TrieNode() {
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isLeaf = false;
    }
    void insert(string s){
        TrieNode* curr = this;
        for(char c:s){
            if(curr->child[c-'a']==NULL){
                TrieNode* nod = new TrieNode();
                curr->child[c-'a'] = nod;
            }
            curr = curr->child[c-'a'];
        }
        curr->isLeaf = true;
    }
};
int wordBreak(string A, vector<string> &B) {
    // code here
    TrieNode* root = new TrieNode();
    int n = A.length();
    for(string s : B){
        root->insert(s);
    }
    vector<bool> dp(n, false);
    for(int i=0;i<n;i++){
        if(i-1 == -1 || dp[i-1]){
            TrieNode* curr = root;
            for(int j=i;j<n;j++){
                char c = A[j];
                if(curr->child[c-'a']==NULL) break;
                curr = curr->child[c-'a'];
                if(curr->isLeaf){
                    dp[j] = true;
                }
            }
        }
    }
    return dp[n-1];
}