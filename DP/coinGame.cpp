#include <bits/stdc++.h>
using namespace std;
int findWinner(int n, int x, int y) {
    // code here
    vector<bool> dp(n+1, false);
    dp[0] = false;
    dp[1] = true;
    for(int i=1;i<=n;i++){
        if(i-1>=0 && !dp[i-1]) dp[i] = true;
        else if(i-x>=0 && !dp[i-x]) dp[i] = true;
        else if(i-y>=0 && !dp[i-y]) dp[i] = true;
    }
    return dp[n];
}
int main(){
    int n=5, x=2, y=3;
    cout<<findWinner(n,x,y);
    return 0;
}