#include <bits/stdc++.h>
using namespace std;
int ways(string& s, int i, int j, int req, vector<vector<vector<int>>>& dp){
    if(i>j) return 0;
    if(i==j){
        if(req == 1){
            return (s[i] == 'T')?1:0;
        }
        else{
            return (s[i] == 'F')?1:0;
        }
    }
    if(dp[i][j][req]!=-1) return dp[i][j][req];
    int res = 0;
    for(int k=i+1;k<j;k+=2){
        int lt = ways(s,i,k-1,1, dp);
        int lf = ways(s,i,k-1, 0, dp);
        int rt = ways(s, k+1,j, 1, dp);
        int rf = ways(s, k+1, j, 0, dp);
        if(s[k] == '&'){
            if(req){
                res += (lt* rt);
            }
            else{
                res += (lf* rt + lf*rf + lt*rf);
            }
        }
        else if(s[k] == '|'){
            if(req){
                res += (lt * rt + lf* rt + lt * rf);
            }
            else res += (lf*rf);
        }
        else if(s[k] == '^'){
            if(req){
                res += (lt*rf + lf* rt);
            }
            else res += (lt* rt + lf*rf);
        }
    }
    return dp[i][j][req] = res;
}
int countWays(string &s) {
    // code here
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return ways(s, 0, n-1, 1, dp);
}
int main(){
    string s = "T|F&T^F";
    cout<<countWays(s)<<endl;
}