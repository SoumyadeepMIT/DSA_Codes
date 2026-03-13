#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<int>& conn, vector<bool>& vis, int u){
vis[u] = true;
conn.push_back(u);
for(int nei: adj[u]){
    if(!vis[nei]){
        dfs(adj, conn, vis, nei);
    }
}
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
vector<vector<int>> adj(n);
vector<bool> vis(n, false);
for(vector<int> a: astronaut){
    adj[a[0]].push_back(a[1]);
    adj[a[1]].push_back(a[0]);
}
vector<int> countrySize;
for(int i=0;i<n;i++){
    vector<int> conn;
    if(!vis[i]){
        dfs(adj, conn, vis, i);
    }
    countrySize.push_back(conn.size());
}
int res = 0;
for(int i=0;i<countrySize.size();i++){
    for(int j=i+1;j<countrySize.size();j++){
        res+=(countrySize[i] * countrySize[j]);
    }
}
return res;
}
int main(){
    int n = 5, p = 3;
    vector<vector<int>> astronaut = {{0, 1}, {2, 3}, {0, 4}};
    cout << journeyToMoon(n, astronaut) << endl;
    return 0;
}