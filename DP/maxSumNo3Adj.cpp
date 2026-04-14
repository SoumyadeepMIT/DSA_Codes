#include <bits/stdc++.h>
using namespace std;
int findMaxSum(vector<int>& arr) {
    // Code Here
    int n = arr.size();
    if(n==1) return arr[0];
    if(n==2) return arr[0] + arr[1];
    if(n==3)return max(arr[0] + arr[1], max(arr[1] + arr[2], arr[2] + arr[0]));
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[1], max(arr[1] + arr[2], arr[2] + arr[0]));
    for(int i=3;i<n;i++){
        dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]));
    }
    return dp[n-1];
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << findMaxSum(arr) << endl;
    return 0;
}