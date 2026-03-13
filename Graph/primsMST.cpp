#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<pair<int,int>>> adj(V);
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    for(vector<int> e: edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    parent[0] = -1;
    key[0] = 0;
    for(int i=0;i<V-1;i++){
        int minInd = -1;
        int minKey = INT_MAX;
        for(int j=0;j<V;j++){
            if(!mst[j] && key[j]<minKey){
                minInd = j;
                minKey = key[j];
            }
        }
        mst[minInd] = true;
        for(pair<int,int> p: adj[minInd]){
            if(!mst[p.first] && p.second<key[p.first]){
                key[p.first] = p.second;
                parent[p.first] = minInd;
            }
        }
    }
    int res = 0;
    for(int n:key) res+=n;
    return res;
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}};
    cout<<spanningTree(V, edges);
}