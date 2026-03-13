#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<int>& res, int nod, vector<bool>& vis){
    if(vis[nod]) return;
    vis[nod] = true;
    res.push_back(nod);
    for(int v: adj[nod]){
        if(!vis[v]){
            dfs(adj, res, v, vis);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    vector<int> res;
    int n = adj.size();
    vector<bool> vis(n, false);
    dfs(adj, res, 0, vis);
    return res;
}
int main(){
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector<int> res = dfs(adj);
    for(int v: res){
        cout << v << " ";
    }
    return 0;
}