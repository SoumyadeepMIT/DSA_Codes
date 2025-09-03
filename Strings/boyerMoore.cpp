#include <bits/stdc++.h> 
using namespace std;
vector<int> patternSearch(string text, string pattern) {
    // Write your code here.
    string txt = pattern + "#" + text;
    int n = txt.size();
    vector<int> dp(n,0);
    vector<int> res;
    for(int i=1;i<n;i++){
        int prevId = dp[i-1];
        while(prevId>0 && txt[i]!=txt[prevId]){
            prevId = dp[prevId - 1];
        }
        dp[i] = prevId + (txt[prevId] == txt[i]?1:0);
        if(dp[i] == pattern.length())
            res.push_back(i-(2*pattern.length()));
    }
    if(res.size() == 0) res.push_back(-1);
    return res;
}
int main(){
    string text = "ABAAAABAACD";
    string pattern = "ABA";
    vector<int> res = patternSearch(text, pattern);
    for(int i: res) cout<<i<<" ";
    return 0;
}