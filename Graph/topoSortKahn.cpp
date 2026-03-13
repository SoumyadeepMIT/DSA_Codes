#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<int> ind(V, 0);
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        ind[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> qu;
    for(int i=0;i<V;i++){
        if(ind[i]==0){
            qu.push(i);
        }
    }
    vector<int> res;
    while(!qu.empty()){
        int nod = qu.front();
        qu.pop();
        res.push_back(nod);
        for(int neigh: adj[nod]){
            ind[neigh]--;
            if(ind[neigh] == 0){
                qu.push(neigh);
            }
        }
    }
    return res;
}
int main(){
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    vector<int> res = topoSort(V, edges);
    for(int i: res){
        cout << i << " ";
    }
}