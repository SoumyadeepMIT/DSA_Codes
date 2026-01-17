#include <bits/stdc++.h>
using namespace std;
int minCost(int n, int m, vector<int>& x, vector<int>& y) {
    //  code here
    int hstrips = 1,vstrips = 1;
    sort(x.begin(),x.end());
    sort(y.begin(), y.end());
    int i = m-2;
    int j = n-2;
    int res = 0;
    while(i>=0 && j>=0){
        if(x[i]>=y[j]){
            res+=x[i--]*hstrips;
            vstrips++;
        }
        else{
            res+=y[j--]*vstrips;
            hstrips++;
        }
    }
    while(i>=0){
        res+=x[i--]*hstrips;
    }
    while(j>=0){
        res+=y[j--]*vstrips;
    }
    return res;
}
int main() {
    
    int n = 4, m = 6;
    vector<int> x = {2, 1, 3, 1, 4};
    vector<int> y = {4, 1, 2};

    cout << minCost(n, m, x, y) << endl;
    return 0;
}