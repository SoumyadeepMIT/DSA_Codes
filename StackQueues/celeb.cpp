#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    vector<int> rsum(n, 0);
    vector<int> csum(n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rsum[i] += mat[i][j];
            csum[j] += mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(csum[i]==n && rsum[i] == 1) return i;
    }
    return -1;
}
int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };
    cout << celebrity(mat) << endl;
    return 0;
}