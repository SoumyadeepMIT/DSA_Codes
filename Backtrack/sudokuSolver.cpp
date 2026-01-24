#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, int num, vector<vector<int>>& mat){
    for(int i=0;i<9;i++){
        if(mat[i][c] == num || mat[r][i] == num) return false;
    }
    int sr = r - (r%3);
    int sc = c - (c%3);
    for(int i = sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(mat[i][j] == num) return false;
        }
    }
    return true;
}
bool solver(vector<vector<int>>& mat, int r, int c){
    if (c == 9) {
        r++;
        c = 0;
    }
    if (r == 9) return true;

    if(mat[r][c]!=0){
        return solver(mat,r,c+1);
    }
    for(int n = 1;n<=9;n++){
        if(isSafe(r,c,n,mat)){
            mat[r][c] = n;
            if(solver(mat, r, c+1)) return true;
            mat[r][c] = 0;
        }
    }
    return false;
}
void solveSudoku(vector<vector<int>> &mat) {
    // code here
    solver(mat, 0, 0);
}

int main() {
    vector<vector<int>> mat = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(mat);

    for (const auto& row : mat) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}