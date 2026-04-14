#include <bits/stdc++.h>
using namespace std;
int knapSack(vector<int>& val, vector<int>& wt, int cap) {
    // code here
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(j<wt[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-wt[i-1]] + val[i-1]);
            }
        }
    }
    return dp[n][cap];
}
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int cap = 50;
    cout << knapSack(val, wt, cap) << endl;
    return 0;
}