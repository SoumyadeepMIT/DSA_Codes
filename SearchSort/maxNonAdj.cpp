#include <bits/stdc++.h> 
using namespace std;
int findMaxSum(vector<int>& arr) {
    // code here
    int n = arr.size();
    if(n==1) return arr[0];
    int sl = 0;
    int l = arr[0];
    int res = 0;
    for(int i=1;i<n;i++){
        res = max(sl+arr[i], l);
        sl = l;
        l = res;
    }
    return res;
}
int main(){
    vector<int> arr = {6, 5, 5, 7, 4};
    cout<<findMaxSum(arr);
    return 0;
}