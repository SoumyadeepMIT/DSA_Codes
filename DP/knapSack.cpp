#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j-wt[i-1]>=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}