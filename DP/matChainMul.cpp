#include <bits/stdc++.h>
using namespace std;
int mulRecur(vector<int>& arr, vector<vector<int>>& dp,int i, int j){
    if(i+1==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res = INT_MAX;
    for(int k=i+1;k<j;k++){
        res = min(res, mulRecur(arr, dp, i,k)+mulRecur(arr, dp, k,j) + (arr[i] * arr[k] * arr[j]));
    }
    return dp[i][j] = res;
}
int matrixMultiplication(vector<int> &arr) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return mulRecur(arr, dp, 0, n-1);
}
int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(arr);
    return 0;
}