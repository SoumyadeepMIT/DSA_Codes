#include <bits/stdc++.h> 
using namespace std;
int findStepKeyIndex(vector<int>& arr, int k, int x) {
    // code here
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x) return i;
    }
    return -1;
}
int main(){
    vector<int> arr = {4, 5, 6, 7, 6};
    cout<<findStepKeyIndex(arr,1,6);
    return 0;
}