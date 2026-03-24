#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    TrieNode* child[26];
    bool isLeaf;
    vector<string> vec;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isLeaf = false;
    }
    void insert(string word){
        TrieNode* curr = this;
        for(char c:word){
            if(curr->child[c-'a'] == NULL){
                TrieNode* nod = new TrieNode();
                curr->child[c-'a'] = nod;
            }
            curr = curr->child[c-'a'];
            curr->vec.push_back(word);
        }
        curr->isLeaf = true; 
    }
};
vector<vector<string>> displayContacts(int n, string contact[], string s) {

    set<string> st(contact, contact+n);

    TrieNode* root = new TrieNode();

    for(auto &c : st){
        root->insert(c);
    }

    TrieNode* curr = root;
    vector<vector<string>> res;

    int i = 0;

    while(i < s.length()){

        char c = s[i];

        if(curr->child[c-'a'] == NULL)
            break;

        curr = curr->child[c-'a'];

        res.push_back(curr->vec);

        i++;
    }

    while(i < s.length()){
        res.push_back({"0"});
        i++;
    }

    return res;
}