#include <bits/stdc++.h>
using namespace std;
vector<int> singleNum(vector<int>& arr) {
    // Code here.
    int xo = 0;
    for(int n: arr){
        xo ^= n;
    }
    xo &= -xo;
    vector<int> res(2,0);
    for(int n:arr){
        if((n&xo)) res[0]^= n;
        else res[1]^=n;
    }
    if(res[0]>res[1]) swap(res[0], res[1]);
    return res;
}
int main() {
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> res = singleNum(arr);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}