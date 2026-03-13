#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recstack,int nod){
    if(recstack[nod]) return true;
    if(vis[nod]) return false;
    
    vis[nod] = true;
    recstack[nod]=true;
    for(int v: adj[nod]){
        if(dfs(adj, vis, recstack, v)) return true;
    }
    recstack[nod] = false;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adj(V);
    for(vector<int> e: edges){
        adj[e[0]].push_back(e[1]);
    }
    vector<bool> vis(V, false);
    vector<bool> recstack(V, false);
    for(int i=0;i<V;i++){
        if(!vis[V] && dfs(adj, vis, recstack, i)) return true;
    }
    return false;
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << isCyclic(V, edges) << endl;
    return 0;
}