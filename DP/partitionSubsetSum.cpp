#include <bits/stdc++.h>
using namespace std;
bool equalPartition(vector<int>& arr) {
    // code here
    int sum = 0;
    for(int n: arr) sum +=n;
    if(sum%2!=0) return false;
    sum/=2;
    vector<bool> prev(sum+1, false), curr(sum+1, false);
    prev[0] = true;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<=sum;j++){
            if(j<arr[i]){
                curr[j] = prev[j];
            }
            else{
                curr[j] = (prev[j] || prev[j -arr[i]]);
            }
        }
        prev = curr;
    }
    return curr[sum];
}
int main(){
    vector<int> arr = {1, 5, 11, 5};
    cout<<equalPartition(arr);
    return 0;
}