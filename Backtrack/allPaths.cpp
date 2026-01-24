#include <bits/stdc++.h>
using namespace std;

void paths(int i, int j, int n, int m, vector<int>& temp, vector<vector<int>>& res, vector<vector<int>>& grid){
    
    if(i<0 || j<0 || i>=n || j>=m) return;
    temp.push_back(grid[i][j]);
    if(i==n-1 && j==m-1){
        res.push_back(temp);
        temp.pop_back();
        return;
    }
    paths(i+1, j, n, m, temp, res, grid);
    paths(i, j+1, n, m, temp, res, grid);
    temp.pop_back();
    return;
}
vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid) {
    // code here
    vector<int> temp;
    vector<vector<int>> res;
    paths(0,0,n,m,temp,res, grid);
    return res;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> allPaths = findAllPossiblePaths(n, m, grid);
    
    cout << "All possible paths from top-left to bottom-right:" << endl;
    for (const auto& path : allPaths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}