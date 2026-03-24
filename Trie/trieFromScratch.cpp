// User function template for C++
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    TrieNode* child[26];
    bool isLeaf;
    TrieNode(){
        isLeaf = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};
class Trie {
  public:
    TrieNode* root;
    Trie() {
        // implement Trie
        root = new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* curr = root;
        for(char c:word){
            if(curr->child[c-'a']==NULL){
                TrieNode* nod = new TrieNode();
                curr->child[c-'a'] = nod;
            }
            curr = curr->child[c-'a'];
        }
        curr->isLeaf = true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* curr = root;
        for(char c:word){
            if(curr->child[c-'a']==NULL) return false;
            curr = curr->child[c-'a'];
        }
        return curr->isLeaf;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* curr = root;
        for(char c:word){
            if(curr->child[c-'a']==NULL) return false;
            curr = curr->child[c-'a'];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    string word = "hello";
    obj->insert(word);
    cout << obj->search(word) << endl;
    cout << obj->isPrefix(word) << endl;
    return 0;
}