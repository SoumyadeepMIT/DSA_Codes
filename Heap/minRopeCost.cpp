#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for(int num:arr){
        pq.push(num);
    }
    int res = 0;
    while(pq.size()>=2){
        int l1 = pq.top();
        pq.pop();
        int l2 = pq.top();
        pq.pop();
        res+=(l1+l2);
        pq.push(l1+l2);
    }
    return res;
}
int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout<<minCost(arr);
    return 0;
}