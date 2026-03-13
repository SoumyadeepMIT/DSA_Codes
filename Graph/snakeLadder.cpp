#include <bits/stdc++.h>
using namespace std;
int snakesAndLadders(vector<vector<int>>& board) {
    queue<pair<int,int>> qu;
    int n = board.size();
    vector<bool> vis(n*n, false);
    qu.push({1,0});
    vis[0] = true;
    while(!qu.empty()){
        pair<int,int> p = qu.front();
        qu.pop();
        int num = p.first;
        int mov = p.second;
        for(int i=1;i<=6;i++){
            int nexNum = p.first + i;
            int r = (nexNum -1)/ n;
            int c = (nexNum - 1)% n;
            c = (r%2==0)?c:n-c-1;
            r = n-r-1;
            if(board[r][c]!=-1){
                nexNum = board[r][c];
            }
            if(nexNum>n*n) continue;
            if(nexNum == n*n) return mov+1;
            if(!vis[nexNum-1]){
                vis[nexNum-1] = true;
                qu.push({nexNum, mov+1});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    cout<<snakesAndLadders(board)<<endl;
}