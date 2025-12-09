#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<vector<int>> &adj, vector<bool> &vis,int par, int nod){
	vis[nod] = true;
	vector<int> neigh = adj[nod];
	for(int i:neigh){
		if(!vis[i]){
			if(isCycle(adj,vis,nod,i)) return true;
		}
		else{
			if(i!=par) return true;
		}
	}
	return false;
}
bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
	// Write your code here
	vector<vector<int>> adj(n);
	vector<bool> vis(n,false);
	for(vector<int> e:edgeList){
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	if(isCycle(adj, vis, -1, 0))
		return false;
	for(int i=0;i<n;i++){
		if(!vis[i]) return false;
	}
	return true;
}
int main(){
    int n = 7;
    vector<vector<int>> edgeList = {
        {0,1},
        {0,4},
        {1,2},
        {1,3},
        {4,5},
        {4,6}};
    if(isGraphTree(n, edgeList)) cout<<"Graph is a tree";
    else cout<<"Graph is not a tree";
    return 0;
}