#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.
    unordered_map<int,int> um;
    for(char c:s) um[c]++;
    vector<pair<char,int>> res;
    for(auto it:um){
        if(it.second>1) res.push_back({it.first,it.second});
    }
    sort(res.begin(),res.end());
    return res;
}
int main(){
    vector<pair<char,int>> res = duplicate_char("banana",6);
    for(auto it:res)cout<<it.first<<" "<<it.second<<endl;
    return 0;
}