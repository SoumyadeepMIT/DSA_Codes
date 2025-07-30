#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &mat) {
    // code here
    int row = mat.size();
    int col = mat[0].size();
    int req = (row*col+1)/2;
    int minv = INT_MAX;
    int maxv = INT_MIN;
    for(int i=0;i<row;i++){
        minv = min(minv,mat[i][0]);
        maxv = max(maxv, mat[i][col-1]);
    }
    int lo = minv;
    int hi = maxv;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int tot = 0;
        for(int i=0;i<row;i++){
            tot+=upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        if(tot<req) lo = mid+1;
        else hi = mid;
    }
    return lo;
}
int main(){
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout<<median(mat);
    return 0;
}