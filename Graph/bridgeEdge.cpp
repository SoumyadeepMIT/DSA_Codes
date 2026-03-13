#include <bits/stdc++.h>
using namespace std;
void dfs(int c, vector<bool>& vis, vector<vector<int>>& adj){
    for(int neigh: adj[c]){
        if(!vis[neigh]){
            vis[neigh] = true;
            dfs(neigh, vis, adj);
        }
    }
}
bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    // Code here
    vector<vector<int>> adj(V);
    for(vector<int> e: edges){
        if((e[0]==c && e[1]==d) || (e[0]==d && e[1]==c)) continue;
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<bool> vis(V, false);
    vis[c]=true;
    dfs(c, vis, adj);
    return !vis[d];
}
int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    int c = 1, d = 3;
    cout << isBridge(V, edges, c, d) << endl; // Output: 1 (true)
    return 0;
}