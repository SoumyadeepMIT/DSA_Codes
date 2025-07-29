#include <bits/stdc++.h>
using namespace std;
int minSwap(vector<int>& arr, int k) {
    // code here
    int c = 0;
    for(int n:arr){
        if(n<=k) c++;
    }
    int res = 0;
    int ans = 0;
    for(int i=0;i<c;i++){
        if(arr[i]>k)res++;
    }
    ans = res;
    for(int i=c;i<arr.size();i++){
        if(arr[i]>k)res++;
        if(arr[i-c]>k)res--;
        ans = min(ans, res);
    }
    return ans;
}
int main(){
    vector<int> arr = {2, 7, 9, 5, 8, 7, 4};
    int k = 6;
    cout<<minSwap(arr,k);
}