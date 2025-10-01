#include <bits/stdc++.h> 
using namespace std;
int minSwaps(vector<int>& arr) {
    // Code here
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    int sc = 0;
    unordered_map<int,int> um;
    for(int i=0;i<arr.size();i++) um[arr[i]] = i;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=temp[i]){
            sc++;
            int j = um[temp[i]];
            swap(arr[i], arr[j]);
            um[arr[i]] = i;
            um[arr[j]] = j;
        }
    }
    return sc;
}
int main(){
    vector<int> arr = {10, 19, 6, 3, 5};
    cout<<minSwaps(arr);
    return 0;
}