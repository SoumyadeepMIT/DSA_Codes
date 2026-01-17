#include <bits/stdc++.h>
using namespace std;
int findMinDiff(vector<int>& arr, int m) {
    // code here
    int res = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i=0;i+m-1<arr.size();i++){
        res = min(res, arr[i+m-1] - arr[i]);
    }
    return res;
}
int main(){
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    cout<<findMinDiff(arr, m);
}