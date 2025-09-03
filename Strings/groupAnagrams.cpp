#include <bits/stdc++.h> 
using namespace std;
vector<vector<string>> anagrams(vector<string>& arr) {
    // code here
    unordered_map<string, vector<string>> um;
    for(string s:arr){
        string t = s;
        sort(t.begin(),t.end());
        um[t].push_back(s);
    }
    vector<vector<string>> res;
    for(auto it: um){
        res.push_back(it.second);
    }
    return res;
}
int main(){
    vector<string> sa = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> res = anagrams(sa);
    for(vector<string> vec: res){
        for(string s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }
}