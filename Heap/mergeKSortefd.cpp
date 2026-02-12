#include <bits/stdc++.h> 
using namespace std;
vector<int> mergeArrays(vector<vector<int>> &mat) {
    // Code here
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<mat.size();i++){
        pq.push({mat[i][0], {i,0}});
    }
    vector<int> res;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        int v = t.first;
        int i = t.second.first;
        int j = t.second.second;
        res.push_back(v);
        if(j+1<mat[i].size()){
            pq.push({mat[i][j+1], {i, j+1}});
        }
    }
    return res;
}
int main(){
    vector<vector<int>> mat= {{1, 3, 5, 7}, 
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};
    vector<int> res = mergeArrays(mat);
    for(int n:res){
        cout<<n<<' ';
    }
}