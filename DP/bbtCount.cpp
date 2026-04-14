#include <bits/stdc++.h>
using namespace std;
int countBT(int h) {
    // code here
    if(h<=1) return 1;
    vector<int> dp(h+1);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=h;i++){
        dp[i] = dp[i-1] * (2*dp[i-2] + dp[i-1]);
    }
    return dp[h];
}
int main() {
    int h = 4;
    cout << countBT(h) << endl;
    return 0;
}