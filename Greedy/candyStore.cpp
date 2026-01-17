#include <bits/stdc++.h>
using namespace std;
vector<int> minMaxCandy(vector<int>& prices, int k) {
    // Code here
    int n = prices.size();
    int can = prices.size();
    sort(prices.begin(), prices.end());
    vector<int> res = {0, 0};
    int i = 0;
    while(n>0){
        res[0] += prices[i];
        res[1] += prices[can-i-1];
        n -= (k+1);
        i++;
    }
    return res;
}
int main() {
    vector<int> prices = {3, 2, 1, 4};
    int k = 2;
    vector<int> res = minMaxCandy(prices, k);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}