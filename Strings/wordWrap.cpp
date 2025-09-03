#include <bits/stdc++.h> 
using namespace std;
int solve(int curr,vector<int>& arr,int n, vector<int>& dp, int k){
    if(curr>=n){
        return 0;
    }
    if(dp[curr]!=-1) return dp[curr];
    int sum=0;
    int tot = 0;
    int res = INT_MAX;
    for(int i=curr;i<n;i++){
        sum+=arr[i];
        tot = sum+(i-curr);
        if(tot>k) break;
        if(i!=n-1){
            int temp = (k-tot) * (k-tot) + solve(i+1,arr,n,dp,k);
            res = min(res,temp);
        }
        else{
            res = 0;
        }
    }
    return dp[curr] = res;
}
int solveWordWrap(vector<int> arr, int k) {
    // Code here
    int n = arr.size();
    vector<int> dp(n,-1);
    return solve(0,arr,n, dp, k);
}
int main(){
    vector<int> arr = {3,2,2,5};
    int k = 6;
    cout<<solveWordWrap(arr,k);
    return 0;
}