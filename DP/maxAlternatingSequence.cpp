#include <bits/stdc++.h>
using namespace std;
int alternatingMaxLength(vector<int>& arr) {
    // Code here
    int n = arr.size();
    int inc = 1, dec = 1;
    int res = 1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            inc = dec + 1;
        }
        else if(arr[i]<arr[i-1]){
            dec = inc + 1;
        }
        res = max(inc, dec);
    }
    return res;
}
int main() {
    vector<int> arr = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << alternatingMaxLength(arr) << endl;
    return 0;
}