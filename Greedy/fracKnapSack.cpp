#include <bits/stdc++.h>
using namespace std;
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    vector<vector<double>> knap;
    int n = val.size();
    for(int i=0;i<n;i++){
        knap.push_back({(double)val[i]/wt[i], val[i], wt[i]});
    }
    sort(knap.begin(), knap.end(), [](vector<double>& a, vector<double>& b){
        return a[0]>b[0];
    });
    double res = 0;
    int i=0;
    while(i<n && capacity>0){
        if((int)knap[i][2]<=capacity){
            capacity -= (int)knap[i][2];
            res += knap[i][1];
        }
        else{
            double frac = capacity/knap[i][2];
            capacity = 0;
            res += frac * knap[i][1];
        }
        i++;
    }
    return res;
}
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    
    cout << fractionalKnapsack(val, wt, capacity) << endl;
    
    return 0;
}