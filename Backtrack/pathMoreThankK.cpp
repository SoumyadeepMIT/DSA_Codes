#include <bits/stdc++.h>
using namespace std;
bool exist(vector<vector<int>>& neigh, int V, int k,vector<bool>& vis, int u) {

    for (int i = 0; i < V; i++) {
    if (!vis[i] && neigh[u][i] != -1) {

        // If this edge itself makes path > k
        if (neigh[u][i] >= k)
            return true;

        vis[i] = true;

        if (exist(neigh, V, k - neigh[u][i], vis, i))
            return true;

        vis[i] = false;
    }
    }
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a) {
    //  Code Here
    vector<bool> vis(V, false);
    vector<vector<int>> neigh(V, vector<int>(V,-1));
    for(int i=0;i<3*E;i+=3){
        neigh[a[i]][a[i+1]] = max(neigh[a[i]][a[i+1]],a[i+2]);
        neigh[a[i+1]][a[i]] = max(neigh[a[i+1]][a[i]],a[i+2]);
    }
    vis[0] = true;
    return exist(neigh, V, k, vis, 0);
}

int main() {
    int V = 4, E = 4, k = 60;
    int a[] = {0, 1, 10, 0, 2, 15, 1, 3, 40, 2, 3, 50};
    if (pathMoreThanK(V, E, k, a))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}