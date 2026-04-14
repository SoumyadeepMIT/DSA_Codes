#include <bits/stdc++.h>
using namespace std;
int eggMem(int n, int k, vector<vector<int>>& dp){
    if(dp[n][k]!=-1) return dp[n][k];
    if(k<=1) return k;
    if(n==1) return k;
    int res = INT_MAX;
    for(int i=1;i<=k;i++){
        int cur = max(eggMem(n-1, i-1,dp), eggMem(n,k-i, dp))+1;
        res = min(res,cur);
    }
    return dp[n][k] = res;
}
int eggDrop(int n, int k) {
    // code here
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return eggMem(n, k, dp);
}
int main(){
    int n = 2, k = 10;
    cout << eggDrop(n, k) << endl;
    return 0;
}