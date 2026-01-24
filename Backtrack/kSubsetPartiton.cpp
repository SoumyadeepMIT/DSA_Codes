#include <bits/stdc++.h>
using namespace std;

bool poss(vector<int>& arr, vector<int>& sub, vector<bool>& vis, int ind, int d, int k, int n, int tar){
    if(sub[d] == tar){
        if(d==k-2) return true;
        return poss(arr, sub, vis, 0, d+1, k, n, tar);
    }
    for(int i=ind;i<n;i++){
        if(vis[i]) continue;
        if((sub[d]+arr[i])>tar) continue;
        sub[d]+=arr[i];
        vis[i] = true;
        if(poss(arr, sub, vis, i+1, d, k, n, tar)) return true;
        sub[d] -= arr[i];
        vis[i] = false;
    }
    return false;
}
bool isKPartitionPossible(vector<int> &arr, int k) {
    
    // Your code here
    if(k==1) return true;
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    if(sum%k!=0) return false;
    sum /= k;
    vector<int> sub(k, 0);
    vector<bool> vis(n, false);
    return poss(arr, sub, vis, 0, 0, k, n, sum);
}

int main() {
    vector<int> arr = {2, 1, 4, 5, 6};
    int k = 3;
    
    if(isKPartitionPossible(arr, k)) {
        cout << "The array can be partitioned into " << k << " subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into " << k << " subsets with equal sum." << endl;
    }
    
    return 0;
}