#include <bits/stdc++.h>
using namespace std;
int count(int n, int i,int j, vector<vector<vector<int>>>& dp){
    if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && (j==0 || j==2))) return 0;
    if(n==1) return 1;
    if(dp[n][i][j]!=-1) return dp[n][i][j];
    vector<vector<int>> dir = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    int res = 0;
    for(vector<int> d:dir){
        int x = i + d[0];
        int y = j + d[1];
        res+=count(n-1,x,y,dp);
    }
    return dp[n][i][j] = res;
}
int getCount(int n) {
    // code here
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(4, vector<int>(3, -1)));
    int res = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            res+=count(n,i,j,dp);
        }
    }
    return res;
}
int main() {
    int n = 3;
    cout << getCount(n) << endl;
    return 0;
}