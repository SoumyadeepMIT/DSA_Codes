#include <bits/stdc++.h>
using namespace std;
int bin(vector<vector<int>>& jobs, int i){
    int l = i+1;
    int h = jobs.size() - 1;
    int res = jobs.size();
    while(l<=h){
        int m = l + (h-l)/2;
        if(jobs[m][0] >= jobs[i][1]){
            res = m;
            h = m-1;
        }
        else l = m+1;
    }
    return res;
}
int maxProfit(vector<vector<int>> &jobs) {
    // code here
    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    vector<int> dp(n+1, 0);
    for(int i=n-1;i>=0;i--){
        dp[i] = dp[i+1];
        int nex = bin(jobs, i);
        dp[i] = max(dp[i], jobs[i][2] + dp[nex]);
    }
    return dp[0];
}
int main(){
    vector<vector<int>> jobs = {{1,2,50}, {3,5,20}, {6,19,100}, {2,100,200}};
    cout<<maxProfit(jobs);
    return 0;
}