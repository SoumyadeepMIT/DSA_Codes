#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>> &mat, int k) {
    // code here
    int n = mat.size();
    int lo = mat[0][0];
    int hi = mat[n-1][n-1];
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int p = 0;
        for(int i=0;i<n;i++){
            p += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        if(p<k) lo = mid+1;
        else hi = mid;
    }
    return lo;
}
int main(){
    vector<vector<int>> matrix = 
                        {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {24, 29, 37, 48},
                        {32, 33, 39, 50 }};
    int k = 3;
    int result = kthSmallest(matrix, k);

    cout << result << endl;
    return 0;
}