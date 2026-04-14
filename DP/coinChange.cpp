#include <bits/stdc++.h>
using namespace std;
int count(vector<int>& coins, int sum) {
    // code here.
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector(sum+1, 0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] += dp[i-1][j];
            if((j-coins[i-1])>=0){
                dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> coins = {2, 5, 3, 6};
    int sum=10;
    cout<<count(coins, sum);
    return 0;
}