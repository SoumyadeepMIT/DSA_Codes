#include <bits/stdc++.h>
using namespace std;
int minimumCost(int n, int w, vector<int> &cost) {
    // code here
    vector<int> val;
    vector<int> wt;
    for(int i=0;i<cost.size();i++){
        if(cost[i]!=-1){
            val.push_back(cost[i]);
            wt.push_back(i+1);
        }
    }
    n = val.size();
    int m = 1e9;
    vector<vector<int>> dp(n+1, vector<int>(w+1, m));
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    if(dp[n][w] == m) return -1;
    return dp[n][w];
}
int main(){
    int n = 5, w = 5;
    vector<int> cost = {1, 2, 3, 4, 5};
    cout << minimumCost(n, w, cost) << endl;
    return 0;
}