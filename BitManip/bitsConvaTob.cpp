#include <bits/stdc++.h>
using namespace std;
int countBitsFlip(int a, int b) {
    // code here
    int res = 0;
    while(a!=0 || b!=0){
        if((a&1)^(b&1) == 1) res++;
        a >>= 1;
        b >>= 1;
    }
    return res;
}
int main() {
    int a = 10, b = 20;
    cout << countBitsFlip(a, b) << endl;
    return 0;
}