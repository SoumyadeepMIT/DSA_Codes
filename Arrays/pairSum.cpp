#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> getPairs(vector<int>& arr) {
    // code here
    sort(arr.begin(),arr.end());
    int l = 0;
    int r = arr.size()-1;
    vector<vector<int>> res;
    while(l<r){
        if(arr[l]+arr[r]==0){
            vector<int> temp = {arr[l],arr[r]};
            res.push_back(temp);
            int v = arr[l];
            while(l<r && arr[l]==v)l++;
        }
        else if(arr[l]+arr[r]<0){
            l++;
        }
        else r--;
    }
    return res;
}

int main(){
    vector<int> arr = {6, 1, 8, 0, 4, -9, -1, -10, -6, -5};
    vector<vector<int>> res = getPairs(arr);
    for(vector<int> r:res){
        cout<<r[0]<<" "<<r[1]<<endl;
    }
    return 0;
}