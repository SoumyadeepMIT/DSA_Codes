#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices) {
    // code here
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
    for(int i=n-1;i>=0;i--){
        for(int k=1;k<=2;k++){
            dp[i][k][1] = max(dp[i+1][k][0] - prices[i], dp[i+1][k][1]);
            dp[i][k][0] = max(dp[i+1][k-1][1] + prices[i], dp[i+1][k][0]);
        }
    }
    return dp[0][2][1];
}
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
    return 0;
}