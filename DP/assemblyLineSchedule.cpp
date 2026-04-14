#include <bits/stdc++.h>
using namespace std;
int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e,
                vector<int>& x) {
    // Code Here
    int n = a[0].size();
    vector<int> t1(n);
    vector<int> t2(n);
    t1[0] = e[0] + a[0][0];
    t2[0] = e[1] + a[1][0];
    for(int i=1;i<n;i++){
        t1[i] = min(t1[i-1] + a[0][i], t2[i-1] + a[0][i] + T[1][i]);
        t2[i] = min(t2[i-1] + a[1][i], t1[i-1] + a[1][i] + T[0][i]);
    }
    return min(t1[n-1] + x[0], t2[n-1]+x[1]);
}
int main(){
    vector<vector<int>> a = {{4, 5, 3, 2},
                             {2, 10, 1, 4}};
    vector<vector<int>> T = {{0, 7, 4, 5},
                             {0, 9, 2, 8}};
    vector<int> e = {10, 12};
    vector<int> x = {18, 7};
    cout<<carAssembly(a,T,e,x);
    return 0;
}