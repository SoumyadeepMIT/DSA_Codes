#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& image, int x, int y, int col, vector<vector<bool>>& vis, vector<vector<int>>& dir, int m, int n){
    int org = image[x][y];
    image[x][y] = col;
    for(int i=0;i<4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx<0 || nx>=m || ny<0 || ny>=n || vis[nx][ny] || image[nx][ny]!=org) continue;
        vis[nx][ny] = true;
        dfs(image, nx, ny, col, vis, dir, m, n);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    vis[sr][sc] = true;
    dfs(image, sr, sc, color, vis, dir, m, n);
    return image;
}
int main(){
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for(vector<int> v: ans){
        for(int i: v) cout << i << " ";
        cout << endl;
    }
    return 0;
}