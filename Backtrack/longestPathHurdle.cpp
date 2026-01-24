#include <bits/stdc++.h>
using namespace std;
int path(vector<vector<int>>& matrix, int x, int y, int xd, int yd, int r, int c){
    if(x == xd && y==yd) return 0;
    if(x<0 || y<0 || x>=r || y>=c || matrix[x][y] == 0){
        return -1;
    }
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = -1;
    matrix[x][y] = 0;
    for(int i=0;i<4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        int pl = path(matrix, nx, ny, xd, yd, r, c);
        if(pl!=-1){
            res = max(res, 1 + pl);
        }
    }
    matrix[x][y] = 1;
    return res;
}
int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
    // code here
    if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;
    return path(matrix, xs, ys, xd, yd, matrix.size(), matrix[0].size());
}
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 1}
    };
    int xs = 0, ys = 0; // Starting coordinates
    int xd = 2, yd = 3; // Destination coordinates
    int result = longestPath(matrix, xs, ys, xd, yd);
    if(result != -1) {
        cout << "The longest path length is: " << result << endl;
    } else {
        cout << "No path exists." << endl;
    }
    return 0;
}