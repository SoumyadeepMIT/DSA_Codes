#include <bits/stdc++.h> 
using namespace std;
vector<int> kLargest(vector<int>& arr, int k) {
    // Your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res(k);
    for(int n:arr){
        if(pq.size() == k && n>pq.top()){
            pq.pop();
            pq.push(n);
        }
        else if(pq.size()<k){
            pq.push(n);
        }
    }
    for(int i=k-1;i>=0;i--){
        res[i] = pq.top();
        pq.pop();
    }
    return res;
}
int main(){
    vector<int> arr = {5, 3, 8, 4, 1, 2};
    int k = 3;
    vector<int> result = kLargest(arr, k);
    for(int i : result){
        cout << i << " ";
    }
    return 0;
}