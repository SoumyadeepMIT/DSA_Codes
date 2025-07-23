#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    // code here
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int res = arr[n-1] - arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-k<0)continue;
        int tall = max(arr[i-1]+k,arr[n-1]-k);
        int sho = min(arr[i]-k,arr[0]+k);
        res = min(res,tall - sho);
    }
    return res;
}

int main() {
    int k = 6;
    vector<int> arr = {12, 6, 4, 15, 17, 10};

    int ans = getMinDiff(arr, k);
    cout << ans;

    return 0;
}