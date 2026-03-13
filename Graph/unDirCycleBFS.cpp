#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>>& adj, int nod, vector<bool>& vis){
    queue<pair<int,int>> qu;
    qu.push({nod, -1});
    vis[nod] = true;
    while(!qu.empty()){
        pair<int, int> p = qu.front();
        int v = p.first;
        int par = p.second;
        qu.pop();
        for(int neigh: adj[v]){
            if(!vis[neigh]){
                vis[neigh] = true;
                qu.push({neigh, v});
            }
            else if(neigh!=par) return true;
        }
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
            if(bfs(adj, i, vis)) return true;
    }
    return false;
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1,2}, {2, 3}};
    cout << isCycle(V, edges) << endl;
    return 0;
}