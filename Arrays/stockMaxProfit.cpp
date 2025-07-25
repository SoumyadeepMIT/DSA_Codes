#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int mtn = prices[n-1];
    int res = 0;
    for(int i=n-2;i>=0;i--){
        res = max(res,mtn-prices[i]);
        mtn = max(mtn,prices[i]);
    }
    return res;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maximumProfit(prices);
}