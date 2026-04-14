#include <bits/stdc++.h>
using namespace std;
int maxSquare(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int res=0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i-1][j-1]==1){
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                res=max(res, dp[i][j]);
            }
        }
    }
    return res;
}
int main() {
    vector<vector<int>> mat = {{0, 1, 1, 0},
                               {1, 1, 1, 1},
                               {0, 1, 1, 1},
                               {0, 1, 1, 1}};
    cout << maxSquare(mat) << endl; // Output: 3
    return 0;
}