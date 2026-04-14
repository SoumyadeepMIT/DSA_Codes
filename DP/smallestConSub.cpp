#include <bits/stdc++.h>
using namespace std;
int smallestSumSubarray(vector<int>& a) {
    // Code here
    int n = a.size();
    int mina = a[0];
    int res = a[0];
    for(int i=1;i<n;i++){
        mina = min(mina + a[i], a[i]);
        res = min(res, mina);
    }
    return res;
}
int main() {
    vector<int> a = {1, -2, 3, -4, 5};
    cout << smallestSumSubarray(a) << endl;
    return 0;
}