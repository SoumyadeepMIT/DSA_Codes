#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
    // Code here
    vector<vector<int>> dir = {{2,1}, {2,-1}, {-2,1}, {-2, -1}, {1,2}, {1, -2}, {-1, 2}, {-1, -2}};
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<vector<int>> qu;
    qu.push({knightPos[0]-1, knightPos[1] - 1, 0});
    vis[knightPos[0]-1][knightPos[1]-1] = true;
    while(!qu.empty()){
        vector<int> nod = qu.front();
        qu.pop();
        if(nod[0] == targetPos[0] -1 && nod[1] == targetPos[1]-1){
            return nod[2];
        }
        for(int i=0;i<8;i++){
            int x = nod[0] + dir[i][0];
            int y = nod[1] + dir[i][1];
            if(x>=n || x<0 || y>=n || y<0 || vis[x][y]) continue;
            vis[x][y] = true;
            qu.push({x,y,nod[2]+1});
        }
    }
    return -1;
}
int main(){
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {8, 8};
    int n = 8;
    cout << minStepToReachTarget(knightPos, targetPos, n) << endl;
    return 0;
}