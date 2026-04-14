#include <bits/stdc++.h>
using namespace std;
int permutationCoeff(int n, int k) {
    // Code here
    long long int P = 1;
    int m = 1e9+7;
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P = (P*(n-i))%m ;

    return P;
}
int main(){
    int n=10, k=3;
    cout<<permutationCoeff(n,k);
    return 0;
}