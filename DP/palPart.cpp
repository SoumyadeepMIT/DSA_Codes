#include <bits/stdc++.h>
using namespace std;
bool isPalin(string&s, int i, int j){
    while(i<j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}
int cuts(string&s, int i,int j,vector<vector<int>>& dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i>=j || isPalin(s,i,j)) return dp[i][j]=0;
    int mc = INT_MAX;
    for(int k=i;k<j;k++){
        mc = min(mc, 1+cuts(s,i,k,dp)+cuts(s,k+1,j,dp));
    }
    return dp[i][j] = mc;
}
int palPartition(string &s) {
    // code here
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return cuts(s, 0,n-1,dp);
}
int main(){
    string s = "ababbbabbababa";
    cout<<palPartition(s);
    return 0;
}