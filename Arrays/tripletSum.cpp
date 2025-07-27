#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> &arr, int target,int l,int r){
    while(l<r){
        if(arr[l] + arr[r] == target) return true;
        else if(arr[l] + arr[r]< target) l++;
        else r--;
    }
    return false;
}
bool hasTripletSum(vector<int> &arr, int target) {
    // Code Here
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(solve(arr,target-arr[i],i+1,arr.size()-1)) return true;
    }
    return false;
}
int main(){
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 13;
    if(hasTripletSum(arr,target)) cout<<"Triplet exists";
    else cout<<"Triplet doesn't exist";
    return 0;
}