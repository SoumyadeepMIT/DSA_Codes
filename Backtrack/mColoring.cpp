#include <bits/stdc++.h>
using namespace std;

bool poss(vector<vector<int>>& neigh, int col, int e, vector<int>& color){
    for(int n:neigh[e]){
        if(color[n] == col) return false;
    }
    return true;
}
bool gen(int u, vector<vector<int>>& neigh, int m, int v, vector<int>& color){
    if(u==v) return true;
    for(int i=0;i<m;i++){
        if(poss(neigh, i, u, color)){
            color[u] = i;
            if(gen(u+1, neigh, m, v, color)) return true;
            color[u] = -1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    // code here
    vector<int> color(v,-1);
    vector<vector<int>> neigh(v);
    for(vector<int> e:edges){
        neigh[e[0]].push_back(e[1]);
        neigh[e[1]].push_back(e[0]);
    }
    return gen(0,neigh, m,v,color);
}
int main() {
    int v = 4; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3}
    };
    int m = 3; // Number of colors

    if (graphColoring(v, edges, m)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }

    return 0;
}