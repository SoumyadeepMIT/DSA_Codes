#include <bits/stdc++.h> 
using namespace std;
void solve(int i,int j,string& target, vector<vector<char> > &mat, int idx, int& res){
    if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return;
    if(target[idx] == mat[i][j]){
        if(idx == target.length() -1){
            res++;
            return;
        }
        char t = mat[i][j];
        mat[i][j] = '0';
        solve(i+1,j,target,mat,idx+1,res);
        solve(i,j+1,target,mat,idx+1,res);
        solve(i-1,j,target,mat,idx+1,res);
        solve(i,j-1,target,mat,idx+1,res);
        mat[i][j] = t;
    }
    return;
}
int findOccurrence(vector<vector<char> > &mat, string target) {
    int r = mat.size();
    int c = mat[0].size();
    int res = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            solve(i,j,target, mat, 0, res);
        }
    }
    return res;
}
int main(){
    vector<vector<char>> mat =  
    {{'S','N','B','S','N'},
    {'B','A','K','E','A'},
    {'B','K','B','B','K'},
    {'S','E','B','S','E'}};
    string target = "SNAKES";
    cout<<findOccurrence(mat, target);
}