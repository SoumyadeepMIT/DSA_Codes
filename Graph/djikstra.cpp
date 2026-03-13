#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    // Build adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    
    // Min heap: {distance, node}
    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>
    > pq;
    
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    pq.push({0, src});
    
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto &[v, weight] : adj[u]){
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 5},
        {1, 2, 2},
        {1, 3, 1},
        {2, 1, 3},
        {2, 3, 9},
        {2, 4, 2},
        {3, 4, 4}
    };
    int src = 0;
    
    vector<int> distances = dijkstra(V, edges, src);
    
    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < V; i++){
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    
    return 0;
}