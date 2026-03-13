#include <bits/stdc++.h>
using namespace std;
int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
    unordered_map<int, vector<pair<int,int>>> adj;
    for(vector<int> e: edges){
        adj[e[0]].push_back({e[1], 0});
        adj[e[1]].push_back({e[0], 1});
    }
    vector<int> dist(n+1, INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int,int> t = pq.top();
        pq.pop();
        int w= t.first;
        int u = t.second;
        for(pair<int,int> nei: adj[u]){
            int w2 = nei.second;
            int v = nei.first;
            if(w+w2<dist[v]){
                dist[v] = w + w2;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
}
int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 3}, {2, 4}};
    int src = 1, dst = 5;
    cout << minimumEdgeReversal(edges, n, src, dst);
    return 0;
}