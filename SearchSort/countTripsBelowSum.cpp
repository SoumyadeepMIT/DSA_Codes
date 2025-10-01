#include <bits/stdc++.h> 
using namespace std;
int countTriplets(int n, long long sum, long long arr[]) {
    // Your code goes here
    sort(arr,arr+n);
    int res = 0;
    for(int i=0;i<n;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            long long s = arr[i] + arr[l] + arr[r];
            if(s<sum){
                res+=(r-l);
                l++;
            }
            else{
                r--;
            }
        }
    }
    return res;
}
int main(){
    long long arr[] = {-2, 0, 1, 3};
    int n = 4;
    int sum = 2;
    cout<<countTriplets(n,sum,arr);
    return 0;
}