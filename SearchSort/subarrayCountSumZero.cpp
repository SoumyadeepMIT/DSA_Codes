#include <bits/stdc++.h> 
using namespace std;
int findSubarray(vector<int> &arr) {
    // code here.
    unordered_map<int,int> um;
    int sum = 0;
    int res = 0;
    for(int n:arr){
        sum += n;
        if(sum==0) res++;
        if(um.find(sum)!=um.end()) res+=um[sum];
        um[sum]++;
    }
    return res;
}
int main(){
    vector<int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    cout<<findSubarray(arr);
    return 0;
}