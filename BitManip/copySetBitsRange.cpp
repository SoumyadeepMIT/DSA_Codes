#include <bits/stdc++.h>
using namespace std;
int setSetBit(int x, int y, int l, int r) {
    // code here
    for(int i=l;i<=r;i++){
        int m = 1<<(i-1);
        if(y&m){
            x = x|m;
        }
    }
    return x;
}
int main() {
    int x = 10, y = 13, l = 2, r = 3;
    cout << setSetBit(x, y, l, r) << endl;
    return 0;
}