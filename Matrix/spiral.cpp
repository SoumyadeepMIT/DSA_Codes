#include <bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int fr = 0;
    int fc = 0;
    int lr = n-1;
    int lc = m-1;
    vector<int> res;
    int k = 0;
    while(k<m*n){
        for(int j=fc;k<m*n && j<=lc;j++){
            res.push_back(mat[fr][j]);
            k++;
        }
        fr++;
        for(int i=fr;k<m*n && i<=lr;i++){
            res.push_back(mat[i][lc]);
            k++;
        }
        lc--;
        for(int i=lc;k<m*n && i>=fc;i--){
            res.push_back(mat[lr][i]);
            k++;
        }
        lr--;
        for(int i=lr;k<m*n && i>=fr;i--){
            res.push_back(mat[i][fc]);
            k++;
        }
        fc++;
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}, 
                {13, 14, 15, 16}};
    vector<int> res = spirallyTraverse(mat);
    for(int n:res) cout<<n<<" ";
    return 0;
}