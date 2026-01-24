#include <bits/stdc++.h>
using namespace std;

void preCompute(string s, vector<vector<bool>>& dp){
    int n = s.length();
    for(int i=0;i<n;i++){
        dp[i][i] = true;
    }
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = (s[i] == s[i+1]);
    }
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
        }
    }
}
void gen(vector<vector<string>>& res, int ind, int n, string s, vector<string>& curr, vector<vector<bool>>& dp){
    if(ind == n){
        res.push_back(curr);
        return;
    }
    for(int i=ind;i<n;i++){
        if(dp[ind][i]){
            curr.push_back(s.substr(ind,i-ind+1));
            gen(res, i+1, n, s, curr, dp);
            curr.pop_back();
        }
    }
}
vector<vector<string>> palinParts(string &s) {
    // code here
    int n = s.length();
    vector<vector<bool>> dp(n,vector<bool>(n, false));
    preCompute(s, dp);
    vector<vector<string>> res;
    vector<string> curr;
    gen(res, 0, n, s, curr, dp);
    return res;
}

int main(){
    string s = "geeks";
    vector<vector<string>> partitions = palinParts(s);
    for (const auto& partition : partitions) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}