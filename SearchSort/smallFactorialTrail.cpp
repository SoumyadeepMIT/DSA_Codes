#include <bits/stdc++.h> 
using namespace std;
bool check(int num, int n){
    int count = 0;
    int fac = 5;
    while(fac<=num){
        count += (num/fac);
        fac *= 5;
    }
    return (count>=n);
}
int findNum(int n) {
    // code here
    int l = 1;
    int r = 5*n;
    while(l<r){
        int m = l+(r-l)/2;
        if(check(m,n)){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return r;
}
int main(){
    cout<<findNum(6);
    return 0;
}