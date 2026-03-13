#include <bits/stdc++.h>
using namespace std;
int calc(vector<vector<int>>& cost, vector<vector<int>>& dp, int i, int mask, int n){
    if(mask==((1<<n)-1)){
        return cost[i][0];
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    int res = INT_MAX;
    for(int j=0;j<n;j++){
        if((mask&(1<<j))==0){
            res = min(res, cost[i][j] + calc(cost, dp, j, mask | (1<<j), n));
        }
    }
    return dp[i][mask] = res;
}
int tsp(vector<vector<int>>& cost) {
    // code here
    int mask = 1;
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    return calc(cost, dp, 0, mask,n);
}
int main(){
    int n;
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    cout<<tsp(cost)<<endl;
}