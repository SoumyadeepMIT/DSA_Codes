#include <bits/stdc++.h>
using namespace std;
vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
    // code here
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for(vector<int> e: edges){
        adj[e[0]-1].push_back(e[1]-1);
        ind[e[1]-1]++;
    }
    queue<pair<int,int>> qu;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            qu.push({i, 1});
        }
    }
    vector<int> res(n,0);
    while(!qu.empty()){
        int nod = qu.front().first;
        int t = qu.front().second;
        qu.pop();
        res[nod] = t;
        for(int neigh: adj[nod]){
            ind[neigh]--;
            if(ind[neigh]==0){
                qu.push({neigh, t+1});
            }
        }
    }
    return res;
}
int main(){
    int n = 10, m=13;
    vector<vector<int>> edges = {{1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}};
    vector<int> res = minimumTime(n, edges, m);
    for(int i: res){
        cout << i << " ";
    }
    return 0;
}