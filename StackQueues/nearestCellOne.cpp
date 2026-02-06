#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>>& grid) {
    // code here
    int r = grid.size();
    int c = grid[0].size();
    queue<vector<int>> qu;
    vector<vector<int>> res(r, vector<int>(c, -1));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j] == 1){
                qu.push({i,j,0});
            }
        }
    }
    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    while(!qu.empty()){
        vector<int> f = qu.front();
        res[f[0]][f[1]] = f[2];
        qu.pop();
        for(int i=0;i<4;i++){
            int nx=f[0] + dir[i][0];
            int ny = f[1] + dir[i][1];
            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny] == 0){
                grid[nx][ny] = 1;
                qu.push({nx,ny,f[2]+1});
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> grid = {{0,0,1},{0,1,1},{1,1,0}};
    vector<vector<int>> res = nearest(grid);
    for(auto v: res){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}