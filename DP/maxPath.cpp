#include <bits/stdc++.h>
using namespace std;
int maximumPath(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0] = mat[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = dp[i-1][j];
            if(j==0 && j<m-1){
                dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
            }
            else if(j==m-1 && j>0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            else{
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-1], dp[i-1][j+1]));
            }
            dp[i][j] += mat[i][j];
        }
    }
    int res = 0;
    for(int i=0;i<m;i++){
        res = max(res, dp[n-1][i]);
    }
    return res;
}
int main() {
    vector<vector<int>> mat = {{10, 10, 2, 0, 20, 4},
                               {1, 0, 0, 30, 2, 5},
                               {0, 10, 4, 0, 2, 0},
                               {1, 0, 2, 20, 0, 4}};
    cout << maximumPath(mat) << endl; // Output: 74
    return 0;
}