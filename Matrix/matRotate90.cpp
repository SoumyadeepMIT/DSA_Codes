#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat.size();
    for(int i=0;i<(n/2);i++){
        for(int j=i;j<(n-1-i);j++){
            int temp = mat[i][j];
            mat[i][j] = mat[n-1-j][i];
            mat[n-1-j][i] = mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j] = mat[j][n-1-i];
            mat[j][n-1-i] = temp;
        }
    }
    
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotate(mat);
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}