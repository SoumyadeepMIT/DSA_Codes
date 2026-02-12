#include <bits/stdc++.h> 
using namespace std;
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    // code here
    deque<int> dq;
    vector<int> res;
    int n = arr.size();
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<n; i++){
        res.push_back(arr[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    return res;
}
int main(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxOfSubarrays(arr, k);
    for(int i : result){
        cout << i << " ";
    }
    return 0;
}