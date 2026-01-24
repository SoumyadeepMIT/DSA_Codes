#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c, vector<vector<int>>& maze){
    if(i<0 || j<0 || i>=r || j>=c || maze[i][j]==0) return false;
    return true;
}
void gen(vector<vector<int>>& maze, int i, int j, int r, int c, string path, vector<string>& res){
    if(!isValid(i,j,r,c,maze)) return;
    if(i==r-1 && j==c-1){
        res.push_back(path);
    }
    maze[i][j] = 0;
    gen(maze, i+1, j, r, c, path + "D", res);
    gen(maze, i, j+1, r, c, path + "R", res);
    gen(maze, i-1, j, r, c, path + "U", res);
    gen(maze, i, j-1, r, c, path + "L", res);
    maze[i][j] = 1;
    return;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    vector<string> res;
    string path = "";
    gen(maze, 0, 0, maze.size(), maze[0].size(), path, res);
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> paths = ratInMaze(maze);
    for (const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}