#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>
                            (3, vector<int>(2, 0)));
    for(int day = n-1;day>=0;day--){
        for(int trans = 1;trans<=2;trans++){
            for(int buy=0;buy<2;buy++){
                if(buy==1){
                    dp[day][trans][buy] = max(-prices[day] + dp[day+1][trans][0], dp[day+1][trans][1]);
                }
                else{
                    dp[day][trans][buy] = max(prices[day] + dp[day+1][trans-1][1], dp[day+1][trans][0]);
                }
            }
        }
    }
    return dp[0][2][1];
}
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
    return 0;
}