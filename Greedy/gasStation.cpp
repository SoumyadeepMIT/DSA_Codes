#include <bits/stdc++.h>
using namespace std;
int startStation(vector<int> &gas, vector<int> &cost) {
    //  code here
    int currGas = 0;
    int totGas = 0;
    int n = gas.size();
    int si = 0;
    for(int i=0;i<n;i++){
        currGas += (gas[i]-cost[i]);
        totGas += (gas[i]-cost[i]);
        if(currGas<0){
            si = i+1;
            currGas = 0;
        }
    }
    if(totGas<0) return -1;
    return si;
}
int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<startStation(gas,cost);
    return 0;
}