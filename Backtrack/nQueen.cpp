#include <bits/stdc++.h>
using namespace std;
bool poss(int i,int j, int n, vector<vector<int>>& queens){
    int u = i-1;
    int v = j-1;
    while(u>=0){
        if(queens[u][j]==1) return false;
        u--;
    }
    u=i-1;
    while(u>=0 && v>=0){
        if(queens[u][v]==1) return false;
        u--;
        v--;
    }
    u=i-1;
    v=j+1;
    while(u>=0 && v<n){
        if(queens[u][v]==1) return false;
        u--;
        v++;
    }
    return true;
}
void gen(int n, int i, vector<int>& pos, vector<vector<int>>& res, vector<vector<int>>& queens){
    if(i==n) {
        res.push_back(pos);
        return;
    }
    for(int j=0;j<n;j++){
        if(poss(i,j, n, queens)){
            queens[i][j] = 1;
            pos.push_back(j+1);
            gen(n, i+1, pos, res, queens);
            queens[i][j] = 0;
            pos.pop_back();
        }
    }
    return;
}
vector<vector<int>> nQueen(int n) {
    // code here
    vector<vector<int>> res;
    vector<int> pos;
    vector<vector<int>> queens(n, vector<int>(n,0));
    gen(n, 0, pos, res, queens);
    return res;
}
int main() {
    int n = 4;
    vector<vector<int>> solutions = nQueen(n);
    for (const auto& solution : solutions) {
        for (int col : solution) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}