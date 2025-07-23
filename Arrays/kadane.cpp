#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    // Code here
    int n = arr.size();
    vector<int> dp(n,0);
    dp[0] = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        res=max(dp[i],res);
    }
    return res;
}

int main(){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr); 
    return 0;
}