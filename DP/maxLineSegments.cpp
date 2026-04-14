#include <bits/stdc++.h>
using namespace std;
int maximizeTheCuts(int n, int x, int y, int z) {
    // Your code here
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++){
        if(i-x>=0 && dp[i-x]!=-1) dp[i] = max(dp[i], 1+dp[i-x]);
        if(i-y>=0 && dp[i-y]!=-1) dp[i] = max(dp[i], 1+dp[i-y]);
        if(i-z>=0 && dp[i-z]!=-1) dp[i] = max(dp[i], 1+dp[i-z]);
        if(dp[i] == 0) dp[i] = -1;
    }
    if(dp[n]==-1) return 0;
    return dp[n];
}
int main() {
    int n, x, y, z;
    n = 7;
    x = 2;
    y = 3;
    z = 4;
    cout << maximizeTheCuts(n, x, y, z) << endl;
    return 0;
}