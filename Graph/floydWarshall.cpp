#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int non = 1e+8;
    int n = dist.size();
    for(int k = 0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]==non || dist[k][j]==non) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    int m = 1e+8;
    vector<vector<int>> dist = {{0, 5, m, 10},
                                {m, 0, 3, m},
                                {m, m, 0, 1},
                                {m, m, m, 0}};
    floydWarshall(dist);
    for(vector<int> v: dist){
        for(int n: v) cout<<n<<" ";
        cout<<endl;
    }
}