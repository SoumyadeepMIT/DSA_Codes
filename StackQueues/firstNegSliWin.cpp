#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegInt(vector<int>& arr, int k) {
    // write code here
    deque<int> dq;
    int n=arr.size();
    for(int i=0;i<k;i++){
        if(arr[i]<0) dq.push_back(i);
    }
    vector<int> res;
    for(int i=k;i<n;i++){
        if(!dq.empty()){
            res.push_back(arr[dq.front()]);
        }
        else{
            res.push_back(0);
        }
        if(arr[i]<0){
            dq.push_back(i);
        }
        while(!dq.empty() && dq.front()<=(i-k)){
            dq.pop_front();
        }
    }
    if(!dq.empty()){
        res.push_back(arr[dq.front()]);
    }
    else{
        res.push_back(0);
    }
    return res;
}
int main(){
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int k = 3;
    vector<int> res = firstNegInt(arr, k);
    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}