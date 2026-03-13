#include <bits/stdc++.h>
using namespace std;
class DJS{
vector<int> rank;
vector<int> parent;
public:
    DJS(int n){
        for(int i=0;i<n;i++){
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v){
        int up = find(u);
        int vp = find(v);
        if(rank[up]<rank[vp]){
            parent[up] = vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp] = up;
        }
        else{
            parent[up] = vp;
            rank[vp]++;
        }
    }
};
int kruskalsMST(int V, vector<vector<int>> &edges) {
    // code here
    sort(edges.begin(), edges.end(), [](const vector<int>& e1, const vector<int>& e2){
        return e1[2]< e2[2];
    });
    int res = 0;
    DJS djs(V);
    int te = 0;
    for(vector<int> e: edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(djs.find(u)!=djs.find(v)){
            djs.unite(u,v);
            res+=w;
            te++;
            if(te == V-1) return res;
        }
    }
    return -1;
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}};
    cout<<kruskalsMST(V, edges);
}