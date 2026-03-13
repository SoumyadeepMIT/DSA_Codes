#include <bits/stdc++.h>
using namespace std;
bool hasEulerianPath(vector<vector<int>>& adj,
                            int& start, int n) {
    int odd = 0;

    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            deg += adj[i][j];
        }

        if (deg % 2 != 0) {
            odd++;
            start = i;
        }
    }

    return (odd == 0 || odd == 2);
}

// Perform DFS and build the Eulerian path
void dfs(int u, vector<vector<int>>& adj, 
               vector<int>& path, int n) {
                   
    for (int v = 0; v < n; v++) {
        while (adj[u][v] > 0) {
            adj[u][v]--;
            adj[v][u]--;
            dfs(v, adj, path, n);
        }
    }

    path.push_back(u);
}

// Return the Eulerian path or {-1} if not possible
vector<int> findEulerianPath(vector<vector<int>> adj) {
    int n = adj.size();
    int start = 0;

    if (!hasEulerianPath(adj, start, n)) {
        return {-1};
    }

    // Count total edges BEFORE DFS
    int edgeCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            edgeCount += adj[i][j];

    vector<int> path;
    dfs(start, adj, path, n);

    // Eulerian path must use all edges exactly once
    if ((int)path.size() != edgeCount + 1) {
        return {-1};
    }

    // Convert to 1-based indexing
    for (int& x : path) {
        x += 1;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    vector<int> res = findEulerianPath(adj);

    if (res.size() == 1 && res[0] == -1) {
        cout << -1;
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size() - 1) {
                cout << " -> ";
            }
        }
    }

    return 0;
}