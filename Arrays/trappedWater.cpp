#include <bits/stdc++.h>
using namespace std;
int maxWater(vector<int> &arr) {
    // code here
    int n = arr.size();
    vector<int> left(n,-1);
    vector<int> right(n,-1);
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],arr[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],arr[i+1]);
    }
    int res = 0;
    for(int i=1;i<n-1;i++){
        int pos = min(left[i], right[i]);
        if(pos>arr[i]) res += (pos-arr[i]);
    }
    return res;
}
int main(){
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout<<maxWater(arr);
}