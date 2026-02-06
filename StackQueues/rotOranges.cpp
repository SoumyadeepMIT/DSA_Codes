#include <bits/stdc++.h>
using namespace std;
int orangesRot(vector<vector<int>>& mat) {
    // code here
    queue<vector<int>> qu;
    int fr = 0;
    int r = mat.size();
    int c = mat[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == 2){
                qu.push({i,j,0});
            }
            if(mat[i][j] == 1) fr++;
        }
    }
    if(fr==0) return 0;
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
    while(!qu.empty()){
        vector<int> f = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nx = f[0] + dir[i][0];
            int ny = f[1] + dir[i][1];
            if(nx>=0 && nx<r && ny>=0 && ny<c && mat[nx][ny] == 1){
                qu.push({nx,ny,f[2]+1});
                fr--;
                mat[nx][ny] = 2;
                if(fr==0) return f[2]+1;
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> mat = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };
    cout << orangesRot(mat) << endl;
    return 0;
}