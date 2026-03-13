#include <bits/stdc++.h>
using namespace std;
bool check(int n, vector<vector<int>>& edges, vector<int>& dist, int src){
    dist[src] = 0;
    for(int i=0;i<n-1;i++){
        for(vector<int> e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u]!=INT_MAX && dist[u] + w< dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(vector<int> e: edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(dist[u]!=INT_MAX && dist[u] + w< dist[v]){
            return true;
        }
    }
    return false; 
}
int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    // Code here
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(check(n, edges, dist, i)) return true;
            for(int i=0;i<n;i++){
                if(dist[i]!=INT_MAX) vis[i] = true;
            }
        }
    }
    return false;
}
int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1,1}, {1,2,-1}, {2,3,-1}, {3,0,-1}};
    cout<<isNegativeWeightCycle(n, edges);
}