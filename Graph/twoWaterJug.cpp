#include <bits/stdc++.h>
using namespace std;
int minSteps(int m, int n, int d) {
    // Code here
    queue<vector<int>> qu;
    vector<vector<bool>> vis(m+1,vector<bool>(n+1, false));
    qu.push({0,0,0});
    vis[0][0] = true;
    while(!qu.empty()){
        vector<int> f = qu.front();
        qu.pop();
        int jug1 = f[0];
        int jug2 = f[1];
        int st = f[2];
        if(jug1==d || jug2 == d) return st;
        if(!vis[m][jug2]){
            vis[m][jug2] = true;
            qu.push({m, jug2, st+1});
        }
        if(!vis[jug1][n]){
            vis[jug1][n] = true;
            qu.push({jug1, n, st+1});
        }
        if(!vis[0][jug2]){
            vis[0][jug2] = true;
            qu.push({0, jug2, st+1});
        }
        if(!vis[jug1][0]){
            vis[jug1][0] = true;
            qu.push({jug1, 0, st+1});
        }
        int p12 = min(jug1, n-jug2);
        if(!vis[jug1-p12][jug2+p12]){
            vis[jug1-p12][jug2+p12] = true;
            qu.push({jug1-p12, jug2+p12, st+1});
        }
        int p21 = min(jug2, m-jug1);
        if(!vis[jug1+p21][jug2-p21]){
            vis[jug1+p21][jug2-p21] = true;
            qu.push({jug1+p21, jug2-p21, st+1});
        }
    }
    return -1;
}
int main(){
    int m = 3, n = 5, d = 4;
    cout<<minSteps(m, n, d);
    return 0;
}