#include <bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    // Code here
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for(vector<int> p: prerequisites){
        adj[p[0]].push_back(p[1]);
        indegree[p[1]]++;
    }
    queue<int> qu;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) qu.push(i);
    }
    while(!qu.empty()){
        int nod = qu.front();
        qu.pop();
        for(int neigh: adj[nod]){
            indegree[neigh]--;
            if(indegree[neigh]==0) qu.push(neigh);
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]!=0) return false;
    }
    return true;
}
int main(){
    int n = 4;
    vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2},{2,0}};
    cout << canFinish(n, prerequisites);
    return 0;
}