#include <bits/stdc++.h>
using namespace std;
int minimumDays(int S, int N, int M) {
    // code here
    if((S>6 && (N*6)<(M*7))|| M>N) return -1;
    int res = (S*M)/N;
    if((S*M)%N!=0) res++;
    return res;
    
}
int main()
{
    int S = 10, N = 16, M = 2;
    cout<<minimumDays(S, N, M);
    return 0;
}