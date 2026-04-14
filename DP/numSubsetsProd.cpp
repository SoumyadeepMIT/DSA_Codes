#include <bits/stdc++.h>
using namespace std;
int numOfSubsets(vector<int>& arr, int k) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j] += dp[i-1][j/arr[i-1]];
            }
        }
    }
    return dp[n][k]-1;
}
int main() {
    vector<int> arr = {1, 2, 3};
    int k = 6;
    cout << "Number of subsets with product less than or equal to " << k << " is " << numOfSubsets(arr, k) << endl;
    return 0;
}