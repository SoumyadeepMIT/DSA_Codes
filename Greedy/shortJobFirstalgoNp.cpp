#include <bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1]>b[1];
    }
};
vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n) {
    // Write your code here
    vector<vector<int>> process;
    for(int i=0;i<n;i++){
        process.push_back({arrivalTime[i], burstTime[i]});
    }
    sort(process.begin(), process.end(), [](vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    });
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    int tasum = 0;
    int wasum = 0;
    int let = process[0][0];
    int i = 0;
    while(i<n && process[i][0]<=let){
        pq.push(process[i]);
        i++;
    }
    while(!pq.empty()){
        vector<int> proc = pq.top();
        pq.pop();
        let+=proc[1];
        tasum+=(let-proc[0]);
        wasum+=(let-proc[0]-proc[1]);
        if(i<n && pq.empty()){
            let = max(let,process[i][0]);
        }
        while(i<n && process[i][0]<=let){
            pq.push(process[i]);
            i++;
        }
    }
    return {(double)wasum/n, (double)tasum/n};
}
int main(){
    vector<int> arrivalTime = {0, 0, 0};
    vector<int> burstTime = {4, 2, 3};
    int n = arrivalTime.size();
    vector<double> res = averageTimes(arrivalTime, burstTime, n);
    for(double v: res) cout<<v<<" ";
    return 0;
}