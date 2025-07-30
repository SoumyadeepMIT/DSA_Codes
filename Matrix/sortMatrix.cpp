#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat) {
    // code here
    vector<int> arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) arr.push_back(mat[i][j]);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n*n;i++){
        mat[i/n][i%n] = arr[i];
    }
    return mat;
}

int main(){
    vector<vector<int>> mat{{5, 4, 7}, {1, 3, 8}, {2, 9, 6}};
    mat = sortedMatrix(mat.size(),mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}