#include <bits/stdc++.h>
using namespace std;
bool bfs(int u, vector<vector<int>>& adj, vector<int>& color){
    queue<int> qu;
    qu.push(u);
    color[u] = 0;
    while(!qu.empty()){
        int nod = qu.front();
        qu.pop();
        for(int nei:adj[nod]){
            if(color[nei]==-1){
                color[nei] = 1 - color[nod];
                qu.push(nei);
            }
            else if(color[nei]==color[nod]) return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<vector<int>> &edges) {
    // Code here
    vector<int> color(V, -1);
    vector<vector<int>> adj(V);
    for(vector<int> e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!bfs(i,adj,color)) return false;
        }
    }
    return true;
}
int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    cout << isBipartite(V, edges) << endl; // Output: 0 (false)
    return 0;
}