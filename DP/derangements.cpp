#include <bits/stdc++.h>
using namespace std;
int countDer(int n) {
    // code here
    vector<int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3;i<=n;i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }
    return dp[n];
}
int main(){
    int n=5;
    cout<<countDer(n);
    return 0;
}