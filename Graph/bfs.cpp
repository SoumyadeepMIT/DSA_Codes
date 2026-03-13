#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &adj) {
    // code here
    vector<int> res;
    queue<int> qu;
    int n = adj.size();
    qu.push(0);
    vector<bool> vis(n, false);
    while(!qu.empty()){
        int nod = qu.front();
        qu.pop();
        if(vis[nod]) continue;
        vis[nod] = true;
        res.push_back(nod);
        for(int v: adj[nod]){
            if(!vis[v]){
                qu.push(v);
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector<int> res = bfs(adj);
    for(int v: res){
        cout << v << " ";
    }
    return 0;
}