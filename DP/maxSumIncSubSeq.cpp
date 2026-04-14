#include <bits/stdc++.h>
using namespace std;
int maxSumIS(vector<int>& arr) {
    // code here
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++){
        dp[i] = arr[i];
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        res = max(dp[i], res);
    }
    return res;
}
int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    cout << "Maximum sum of increasing subsequence is " << maxSumIS(arr) << endl;
    return 0;
}