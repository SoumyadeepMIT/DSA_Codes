#include <bits/stdc++.h>
using namespace std;
int nCr(int n, int r) {
    // code here
    double sum = 1;
    for (int i = 1; i <= r; i++){
        
        sum = sum * (n - r + i) / i;
    }
    return (int)sum;
}
int main(){
    int n = 5, r = 2;
    cout<<nCr(n,r);
    return 0;
}