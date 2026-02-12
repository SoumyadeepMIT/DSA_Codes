#include <bits/stdc++.h> 
using namespace std;
int kthLargest(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + arr[i-1];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int s = pref[j] - pref[i-1];
            if(pq.size()<k){
                pq.push(s);
            }
            else{
                if(s>pq.top()){
                    pq.pop();
                    pq.push(s);
                }
            }
        }
    }
    return pq.top();
}
int main(){
    vector<int> arr = {2,6,4,1};
    int k = 3;
    cout<<kthLargest(arr,k);
    return 0;
}