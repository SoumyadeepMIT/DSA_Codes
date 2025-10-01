#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int>& arr, int k, int n){
    int sum=0;
    int c = 1;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]>n){
            c++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return (c<=k);
}
int findPages(vector<int> &arr, int k) {
    // code here
    if(k>arr.size()) return -1;
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(check(arr,k,m)){
            res = m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout<<findPages(arr,k);
    return 0;
}