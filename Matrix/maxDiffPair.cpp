#include <bits/stdc++.h>
using namespace std;
int findMaxValue(vector<vector<int>>& mat, int n) {
    // Write your code here
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    dp[0][0] = mat[0][0];
    for(int i=1;i<n;i++){
        dp[0][i] = min(dp[0][i-1],mat[0][i]);
    }
    int res = INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                dp[i][j] = min(mat[i][j],dp[i-1][j]);
                continue;
            }
            res = max(res,mat[i][j] - dp[i-1][j-1]);
            dp[i][j] = min({mat[i][j], dp[i-1][j],dp[i][j-1]});
        }
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};

    cout<<findMaxValue(mat,mat.size());
    return 0;
}