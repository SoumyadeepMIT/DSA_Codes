#include <bits/stdc++.h>
using namespace std;
int minSubset(vector<int> &arr) {
    // code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
    sort(arr.begin(), arr.end());
    sum /= 2;
    int n = arr.size();
    int tsum = 0;
    int res = 0;
    for(int i=n-1;i>=0;i--){
        tsum+=arr[i];
        res++;
        if(tsum>sum) return res;
    }
    return res;
}
int main(){
    vector<int> arr = {20, 12, 18, 4};
    cout<<minSubset(arr);
}