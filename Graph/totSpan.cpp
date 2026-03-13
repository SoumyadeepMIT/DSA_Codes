#include <bits/stdc++.h>
using namespace std;
int calcDet(vector<vector<int>>& detMat, int n){
    if(n==1){
        return detMat[0][0];
    }
    if(n==2){
        return detMat[0][0] * detMat[1][1] 
                - detMat[0][1] * detMat[1][0];
    }

    int res = 0;

    for(int l=0;l<n;l++){

        vector<vector<int>> lapMat(n-1);
        int k = 0;

        for(int i=1;i<n;i++){   // skip row 0
            for(int j=0;j<n;j++){
                if(j == l) continue;   // skip column l
                lapMat[k].push_back(detMat[i][j]);
            }
            k++;
        }

        int sign = (l % 2 == 0) ? 1 : -1;

        res += sign * detMat[0][l] * calcDet(lapMat, n-1);
    }

    return res;
}
int countSpanningTrees(vector<vector<int>>& graph, int n, int m) {
    // Write your code here
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(vector<int> g: graph){
        adj[g[0]][g[1]] = 1;
        adj[g[1]][g[0]] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(adj[i][j]==1){
                adj[i][i]++;
                adj[i][j] = -1;
            }
        }
    }
    vector<vector<int>> detMat(n-1);
    int k = 0;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            detMat[k].push_back(adj[i][j]);
        }
        k++;
    }
    int cof = calcDet(detMat, n-1);
    return cof;
}
int main(){
    int n = 4, m = 5;
    vector<vector<int>> graph = {{0,1}, {0,2}, {0,3}, {1,3}, {2,3}};
    cout<<countSpanningTrees(graph, n, m);
}