#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int>& temp){
    int ma = temp[0];
    int res = temp[0];
    for(int i=1;i<temp.size();i++){
        ma = max(temp[i], ma+temp[i]);
        res = max(res, ma);
    }
    return res;
}
int maxRectSum(vector<vector<int>> &mat) {
    // code here
    int r = mat.size();
    int c = mat[0].size();
    int res = INT_MIN;
    for(int i=0;i<r;i++){
        vector<int> temp(c, 0);
        for(int j=i;j<r;j++){
            for(int k=0;k<c;k++){
                temp[k] += mat[j][k];
            }
            int ma = kadane(temp);
            res = max(res, ma);
        }
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 10, 1, 3},
                               {-4, -1, 1, 7, -6}};
    cout << maxRectSum(mat) << endl;
    return 0;
}