#include <bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr) {
    // code here
    int n = arr.size();
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>dp.back()){
            dp.push_back(arr[i]);
        }
        else{
            int ind = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[ind] = arr[i];
        }
    }
    return dp.size();
}
int main() {
    vector<int> arr = {10, 20, 10, 30, 20, 50};
    cout << "Length of the longest increasing subsequence is " << lis(arr) << endl;
    return 0;
}