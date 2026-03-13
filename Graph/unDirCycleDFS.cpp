#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int nod, int parent){
    vis[nod] = true;
    for(int v: adj[nod]){
        if(!vis[v]){
            if(dfs(adj, vis, v, nod)) return true;
        }
        else if(v!=parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<bool> vis(V, false);
    vector<vector<int>> adj(V);
    for(vector<int> e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    for(int i=0;i<V;i++){
        if(!vis[i])
            if(dfs(adj, vis, i, -1)) return true;
    }
    return false;
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1,2}, {2, 3}};
    cout << isCycle(V, edges) << endl;
    return 0;
}