#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>>& adj, vector<bool>& vis, int i,stack<int>& st){
    vis[i] = true;
    for(int nei: adj[i]){
        if(!vis[nei]){
            dfs1(adj, vis, nei, st);
        }
    }
    st.push(i);
}
void dfs2(vector<vector<int>>& trans, vector<bool>& vis, int i){
    vis[i] = true;
    for(int nei: trans[i]){
        if(!vis[nei]){
            dfs2(trans, vis, nei);
        }
    }
}
int kosaraju(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adj(V);
    for(vector<int> e: edges){
        adj[e[0]].push_back(e[1]);
    }
    stack<int> st;
    vector<bool> vis(V, false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs1(adj, vis, i, st);
        }
    }
    vector<vector<int>> trans(V);
    for(int i=0;i<V;i++){
        vis[i] = false;
        for(int nei: adj[i]){
            trans[nei].push_back(i);
        }
    }
    int res = 0;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(!vis[i]){
            res++;
            dfs2(trans, vis, i);
        }
    }
    return res;
}
int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    cout << kosaraju(V, edges) << endl;
    return 0;
}