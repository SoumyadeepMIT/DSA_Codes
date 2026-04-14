#include <bits/stdc++.h>
using namespace std;
int calc(vector<int>& prices, int k, int ind,int buy, vector<vector<vector<int>>>& dp){
    if(k<=0 || ind>=prices.size()) return 0;
    if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];
    int res = INT_MIN;
    if(buy==1){
        res = max(calc(prices, k, ind+1, 1, dp) ,calc(prices, k, ind+1, 0, dp) - prices[ind]);
    }
    else{
        res = max(calc(prices, k, ind + 1 , 0 , dp), calc(prices, k-1, ind + 1, 1, dp) + prices[ind]);
    }
    return dp[ind][k][buy] = res;
}
int maxProfit(vector<int>& prices, int k) {
    // code here
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,-1)));
    return calc(prices, k, 0, 1, dp);
}
int main(){
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << maxProfit(prices, k) << endl;
    return 0;
}