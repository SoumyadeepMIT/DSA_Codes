#include <bits/stdc++.h>
using namespace std;
int freqSum(vector<int>& freq, int i, int j){
    int sum = 0;
    for(int ind = i;ind<=j;ind++){
        sum+=freq[ind];
    }
    return sum;
}
int calc(vector<int>& freq, int i, int j, vector<vector<int>>& dp){
    if(j<i) return 0;
    if(i==j) return freq[i];
    if(dp[i][j] !=-1) return dp[i][j];
    int fsum = freqSum(freq,i,j);
    int minCost = INT_MAX;
    
    for(int ind = i;ind<=j;ind++){
        int c = calc(freq,i,ind-1,dp) + calc(freq,ind+1,j,dp);
        minCost = min(minCost, c);
    }
    return dp[i][j]=minCost + fsum;
}
int minCost(vector<int> &keys, vector<int> &freq) {
    // code here
    int n = freq.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return calc(freq,0,n-1,dp);
}
int main(){
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    cout<<minCost(keys,freq);
    return 0;
}