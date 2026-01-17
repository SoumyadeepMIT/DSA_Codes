#include <bits/stdc++.h>
using namespace std;
int buyMaximumProducts(int n, int k, int price[]) {
    // Write your code here
    vector<pair<int,int>> stocks;
    for(int i=0;i<n;i++){
        stocks.push_back({price[i], i+1});
    }
    sort(stocks.begin(), stocks.end());
    int res = 0;
    for(int i=0;i<n;i++){
        int st = min(stocks[i].second, k/stocks[i].first);
        res+=st;
        k -= stocks[i].first*st;
    }
    return res;
}
int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}