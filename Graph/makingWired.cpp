#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int u){
    if(vis[u]) return;
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(adj, vis, v);
        }
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    int cn = connections.size();
    if(cn<(n-1)) return -1;
    vector<vector<int>> adj(n);
    for(int i=0;i<cn;i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    int cc = 0;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cc++;
            dfs(adj, vis, i);
        }
    }
    return cc-1;
}
int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout << makeConnected(n, connections) << endl;
}