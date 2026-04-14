#include <bits/stdc++.h>
using namespace std;
int minJumps(vector<int>& arr) {
    // code here
    int curp = 0;
    int maxp = 0;
    int n = arr.size();
    int jumps = 0;
    for(int i=0;i<n;i++){
        maxp = max(maxp, i+arr[i]);
        if(maxp>=n-1) return jumps+1;
        if(i == curp){
            if(i==maxp) return -1;
            curp = maxp;
            jumps++;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << minJumps(arr) << endl; // Output: 2
    return 0;
}