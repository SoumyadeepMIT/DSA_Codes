#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i, int j, int r, int c,vector<vector<int>>& mat){
    if(i<0 || j<0 || i>=r || j>=c || mat[i][j]!=1){
        return false;
    }
    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
    for(int d = 0;d<4;d++){
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if(ni>=0 && nj>=0 && ni<r && nj<c && mat[ni][nj]==0){
            return false;
        }
    }
    return true;
}
int findShortestPath(vector<vector<int>> &mat) {
    // code here
    int r = mat.size();
    int c = mat[0].size();
    queue<pair<pair<int,int>, int>> qu;
    for(int i=0;i<r;i++){
        if(isSafe(i, 0, r, c, mat)){
            qu.push({{i, 0}, 1});
        }   
        mat[i][0] = -1;
    }
    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
    while(!qu.empty()){
        pair<pair<int,int>, int> q = qu.front();
        qu.pop();
        int x = q.first.first;
        int y = q.first.second;
        int dist = q.second;
        if(y == c-1) return dist;
        for(int i=0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(isSafe(nx,ny,r,c,mat)){
                qu.push({{nx,ny},dist+1});
                mat[nx][ny] = -1;
            }
        }
    }
    return -1;
}
int main() {
    vector<vector<int>> mat = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };
    
    int shortestPathLength = findShortestPath(mat);
    
    if (shortestPathLength != -1) {
        cout << "The length of the shortest safe route is: " << shortestPathLength << endl;
    } else {
        cout << "No safe route exists from the leftmost to the rightmost column." << endl;
    }
    
    return 0;
}