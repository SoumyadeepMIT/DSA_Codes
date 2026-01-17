#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b,
                              vector<int> d) {
    // code here
    vector<int> out(n+1, -1);
    vector<int> in(n+1, -1);
    vector<int> dia(n+1,-1);
    for(int i=0;i<p;i++){
        out[a[i]] = b[i];
        in[b[i]] = a[i];
        dia[a[i]] = d[i];
    }
    vector<vector<int>> res;
    for(int i=1;i<=n;i++){
        if(out[i]!=-1 && in[i]==-1){
            int curr = i; int mind = INT_MAX;
            while(out[curr]!=-1){
                mind = min(mind, dia[curr]);
                curr = out[curr];
            }
            res.push_back({i,curr,mind});
        }
    }
    sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    });
    return res;
}
void print2dArray(vector<vector<int>> &arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j];
            if (j != arr[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    
    int n = 9, p = 6;
    vector<int> a = {7, 5, 4, 2, 9, 3}, 
                b = {4, 9, 6, 8, 7, 1}, 
                d = {98, 72, 10, 22, 17, 66};

    vector<vector<int>> ans
      = solve(n, p, a, b, d);
      
    print2dArray(ans);
    
    return 0;
}