#include <bits/stdc++.h>
using namespace std;
int countWays(int n, int k) {
    // code here
    if(n==1) return k;
    if(n==2) return k*k;
    vector<int> dp(n+1);
    dp[1] = k;
    dp[2] = k*k;
    for(int i=3;i<=n;i++){
        dp[i] = (k-1) * dp[i-1] + (k-1) * dp[i-2];
    }
    return dp[n];
}
int main() {
    int n, k;
    n = 4;
    k = 3;
    cout << countWays(n, k) << endl;
    return 0;
}