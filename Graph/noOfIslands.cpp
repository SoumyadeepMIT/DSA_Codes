#include <bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, int r, int c){
    if(i<0 || j<0 || i>=r || j>=c) return false;
    return true;
}
void dfs(vector<vector<char>>& grid, vector<vector<int>>& dir,  int r, int c, int i, int j){

    for(int d=0;d<8;d++){
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if(isValid(ni, nj, r, c) && grid[ni][nj]=='L'){
            grid[ni][nj] = 'W';
            dfs(grid, dir, r, c, ni, nj);
        }
    }
}
int countIslands(vector<vector<char>>& grid) {
    // Code here
    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int r = grid.size();
    int c = grid[0].size();
    int res = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='L'){
                grid[i][j] = 'W';
                res++;
                dfs(grid, dir, r, c, i, j);
            }
        }
    }
    return res;
}
int main(){
    vector<vector<char>> grid = {{'W', 'L', 'W', 'W', 'L'},
                                 {'L', 'L', 'W', 'L', 'L'},
                                 {'W', 'L', 'W', 'W', 'W'},
                                 {'W', 'W', 'W', 'L', 'L'}};
    cout << countIslands(grid);
    return 0;
}