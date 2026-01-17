#include <bits/stdc++.h>
using namespace std;
long long maxSum(vector<int>& arr) {
    // code here
    sort(arr.begin(), arr.end());
    int i=0;
    int j = arr.size() -1;
    bool inc = true;
    long long res = 0;
    while(i<j){
        res+=abs(arr[j]-arr[i]);
        if(inc)i++;
        else j--;
        inc = !inc;
    }
    res+=abs(arr[i]-arr[0]);
    return res;
}
int main(){
    vector<int> arr = {4,2,1,8};
    cout<<maxSum(arr);
    return 0;
}