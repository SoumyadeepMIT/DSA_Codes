#include <bits/stdc++.h>
using namespace std;
string findOrder(vector<string> &words) {
    // code here
    vector<vector<int>> adj(26);
    vector<int> ind(26,0);
    vector<bool> ex(26, false);
    for(string w:words){
        for(char c: w)
            ex[c-'a'] = true;
    }
    for(int i=0;i<words.size()-1;i++){
        string w1 = words[i];
        string w2 = words[i+1];
        int n=min(w1.length(), w2.length());
        int j=0;
        while(j<n){
            if(w1[j]!=w2[j]) break;
            j++;
        }
        
        if(j==n){
            if(w2.length()<w1.length()) return "";
            continue;
        }
        adj[(w1[j]-'a')].push_back(w2[j]-'a');
        ind[(w2[j]-'a')]++;
    }
    queue<int> qu;
    for(int i=0;i<26;i++){
        if(ex[i] && ind[i] == 0) qu.push(i);
    }
    string res = "";
    while(!qu.empty()){
        int nod = qu.front();
        qu.pop();
        res+=(char)(nod+'a');
        for(int nei: adj[nod]){
            ind[nei]--;
            if(ind[nei]==0) qu.push(nei);
        }
    }
    for(int i=0;i<26;i++){
        if(ind[i]>0) return "";
    }
    return res;
}
int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout << findOrder(words);
    return 0;
}