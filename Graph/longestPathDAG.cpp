#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int,int>>>& adj, stack<int>& st, vector<bool>& vis, int u){
    vis[u] = true;
    for(pair<int,int> p: adj[u]){
        int v = p.first;
        if(!vis[v]){
            dfs(adj, st, vis, v);
        }
    }
    st.push(u);
}
vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
    // code here
    vector<vector<pair<int,int>>> adj(v);
    for(vector<int> ed: edges){
        adj[ed[0]].push_back({ed[1], ed[2]});
    }
    stack<int> st;
    vector<bool> vis(v, false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(adj, st, vis, i);
        }
    }
    vector<int> res(v, INT_MIN);
    res[src] = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(res[u]!=INT_MIN){
            for(pair<int,int>p: adj[u]){
                int v = p.first;
                int w = p.second;
                if(res[v]<res[u] + w){
                    res[v] = res[u] + w;
                }
            }
        }
    }
    return res;
}
int main(){
    int v = 6, e = 7, src = 0;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {3, 4, -1}, {3, 5, 1}, {4, 5, -2}};
    vector<int> res = maximumDistance(edges, v, e, src);
    for(int d: res){
        if(d==INT_MIN) cout << "INF ";
        else cout << d << " ";
    }
    cout << endl;
    return 0;
}