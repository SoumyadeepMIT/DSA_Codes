#include <bits/stdc++.h>
using namespace std;
int findMinDiff(vector<int>& a, int m) {
    // code here
    sort(a.begin(),a.end());
    int res = INT_MAX;
    for(int i=0;i+m<=a.size();i++){
        res = min(res,a[i+m-1]-a[i]);
    }
    return res;
}

int main(){
    int m = 5;
    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    cout<<findMinDiff(a,m);
    return 0;
}