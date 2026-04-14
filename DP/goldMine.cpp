#include <bits/stdc++.h>
using namespace std;
int maxGold(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    vector<vector<int>> dp(n,vector<int>(n, 0));
    dp=mat;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0)
                dp[j][i]+=max(dp[j][i-1], dp[j+1][i-1]);
            else if(j==n-1){
                dp[j][i]+=max(dp[j][i-1], dp[j-1][i-1]);
            }
            else{
                dp[j][i]+=max(dp[j][i-1], max(dp[j-1][i-1], dp[j+1][i-1]));
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res = max(res, dp[i][n-1]);
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {{1, 3, 1, 5},
                               {2, 2, 4, 1},
                               {5, 0, 2, 3},
                               {0, 6, 1, 2}};
    cout<<maxGold(mat);
    return 0;
}