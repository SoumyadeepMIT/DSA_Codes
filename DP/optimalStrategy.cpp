#include <bits/stdc++.h>
using namespace std;
int maximumAmount(vector<int> &arr) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n, 0));
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
        if(i<n-1){
            dp[i][i+1] = max(arr[i], arr[i+1]);
        }
    }
    for(int l = 3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                            arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}
int main(){
    vector<int> arr = {20, 30, 2, 2, 2, 10};
    cout<<maximumAmount(arr);
    return 0;
}