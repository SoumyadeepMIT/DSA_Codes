#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    bool isLeaf;
    TrieNode* child[26];
    int freq = 0;
    TrieNode() {
        isLeaf = false;;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
    void insert(string s){
        TrieNode* curr = this;
        for(char c:s){
            if(curr->child[c-'a']==NULL){
                TrieNode* nod = new TrieNode();
                curr->child[c-'a'] = nod;
            }
            curr = curr->child[c-'a'];
            curr->freq++;
        }
        curr->isLeaf = true;
    }
    int uniq(string s){
        TrieNode* curr = this;
        int i=0;
        for(char c:s){
            curr=curr->child[c-'a'];
            if(curr->freq == 1) return i;
            i++;
        }
        return s.length() - 1;
    }
    void deleteTrie(TrieNode* root) {
        if (root==nullptr) return;
        
        for (int i=0; i<26; i++) {
            deleteTrie(root->child[i]);
            delete root->child[i];
        }
    }
};
vector<string> findPrefixes(string arr[], int n) {
    // code here
    TrieNode* root = new TrieNode();
    for(int i=0;i<n;i++){
        root->insert(arr[i]);
    }
    vector<string> res;
    for(int i=0;i<n;i++){
        int ind = root->uniq(arr[i]);
        res.push_back(arr[i].substr(0,ind+1));
    }
    root->deleteTrie(root);
    return res;
}
int main() {
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<string> prefixes = findPrefixes(arr, n);
    for (const string& prefix : prefixes) {
        cout << prefix << endl;
    }
    return 0;
}