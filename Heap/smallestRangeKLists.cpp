#include <bits/stdc++.h> 
using namespace std;
vector<int> findSmallestRange(vector<vector<int>>& mat) {
    // Code here
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    int n = mat[0].size();
    int k = mat.size();
    int maxv = INT_MIN;
    for(int i=0;i<k;i++){
        pq.push({mat[i][0], {i, 0}});
        maxv = max(maxv, mat[i][0]);
    }
    int resMin = -1;
    int resMax = -1;
    int range = INT_MAX;
    while(true){
        auto curr = pq.top();
        pq.pop();
        int v = curr.first;
        int r = curr.second.first;
        int c = curr.second.second;
        if(maxv - v <range){
            range = maxv - v;
            resMax = maxv;
            resMin = v;
        }
        if(c+1==n) break;
        pq.push({mat[r][c+1], {r,c+1}});
        maxv = max(maxv, mat[r][c+1]);
    }
    return {resMin, resMax};
}
int main() {

    vector<vector<int>>mat = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    vector<int> res = findSmallestRange(mat);

    cout << res[0] << " " << res[1];

    return 0;
}