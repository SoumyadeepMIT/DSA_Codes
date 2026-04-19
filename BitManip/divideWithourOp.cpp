#include <bits/stdc++.h>
using namespace std;
long long divide(long long dividend, long long divisor) {
    // code here
    int sign = ((dividend<0) ^ (divisor<0))?-1:1;
    long long a = abs(dividend);
    long long b = abs(divisor);
    long long res = 0;
    for(int i=31;i>=0;i--){
        if((b<<i)<=a){
            a-=(b<<i);
            res |= (1LL<<i);
        }
    }
    res *= sign;
    if(res>(1LL<<31-1)) return 1LL<<31-1;
    if(res<(-1*(1<<31))) return -1 * (1<<31);
    return res;
    
}
int main(){
    long long dividend=10, divisor=3;
    cout<<divide(dividend, divisor)<<endl;
    return 0;
}