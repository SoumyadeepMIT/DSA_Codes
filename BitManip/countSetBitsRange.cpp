#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) {
    // code here
    if(n==0) return 0;
    int i = log2(n);
    int fb = i * (1<<(i-1));
    int msb = n - (1<<i) + 1;
    int rem = (n-(1<<i));
    int remb = countSetBits(rem);
    return fb + msb + remb;
}
int main() {
    int n = 6;
    cout << countSetBits(n) << endl;
    return 0;
}