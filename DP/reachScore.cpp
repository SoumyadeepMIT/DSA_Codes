#include <bits/stdc++.h>
using namespace std;
long long int count(long long int n) {
    // Your code here
    vector<int> points = {3, 5, 10};
    vector<vector<long long int>> dp(n+1, vector<long long int>(4, 0));
    for(int i=0;i<=4;i++) dp[0][i] = 1;
    for(int i=1;i<=n;i++){
        for(int j=2;j>=0;j--){
            if(i-points[j]>=0){
                dp[i][j] = dp[i-points[j]][j+1] + dp[i][j+1];
            }
            else dp[i][j] = dp[i][j+1];
        }
    }
    return dp[n][0];
}
int main(){
    long long int n = 8;
    cout << count(n) << endl;
    return 0;
}