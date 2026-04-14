#include <bits/stdc++.h>
using namespace std;
int longestSubseq(vector<int> &arr) {
    // code here
    int n = arr.size();
    unordered_map<int,int> um;
    um[arr[0]] = 1;
    int res = 1;
    for(int i=1;i<n;i++){
        if(um.find(arr[i]-1) == um.end()){
            um[arr[i]] = 1;
        }
        else{
            um[arr[i]] = um[arr[i] - 1] + 1;
            res = max(res, um[arr[i]]);
        }
        if(um.find(arr[i]+1) == um.end()){
            um[arr[i]] = max(um[arr[i]], 1);
        }
        else{
            um[arr[i]] = max(um[arr[i] + 1] + 1, um[arr[i]]);
            res = max(res, um[arr[i]]);
        }
        
    }
    return res;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << longestSubseq(arr) << endl;
    return 0;
}