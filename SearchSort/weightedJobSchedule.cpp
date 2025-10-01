#include <bits/stdc++.h> 
using namespace std;
int bin(vector<vector<int>>& jobs, int i){
    int end = jobs[i][1];
    int l = i+1;
    int r = jobs.size() -1;
    int res = jobs.size();
    while(l<=r){
        int m = (l+r)/2;
        if(jobs[m][0]>=end){
            res = m;
            r=m-1;
        }
        else{
            l = m+1;
        }
    }
    return res;
}
long long int calc(vector<vector<int>>& jobs, vector<long long int>& memo, int i){
    if(i>=jobs.size()) return 0;
    if(memo[i]!=-1 ) return memo[i];
    int next = bin(jobs,i);
    long long int take=calc(jobs,memo,next) + jobs[i][2];
    long long int ntake = calc(jobs, memo, i+1);

    return memo[i] = max(take, ntake);
}
long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    // Write your code here.
    int n = start.size();
    vector<vector<int>> jobs(n);
    for(int i=0;i<n;i++){
        jobs[i].push_back(start[i]);
        jobs[i].push_back(end[i]);
        jobs[i].push_back(profit[i]);
    }
    sort(jobs.begin(), jobs.end());
    vector<long long int> memo(n,-1);

    return calc(jobs, memo, 0);
}
int main(){
    vector<int> start = {1,2,3,3};
    vector<int> end = {3,4,5,6};
    vector<int> prof = {50, 10, 40, 70};
    cout<<findMaxProfit(start,end,prof);
    return 0;
}