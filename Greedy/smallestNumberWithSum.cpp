#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d) {
    // code here
    if(s<1 || s>9*d){
        return "-1";
    }
    string res(d, '0');
    s--;
    for(int i=d-1;i>0;i--){
        if(s>9){
            res[i]='9';
            s-=9;
        }
        else{
            res[i] = '0' + s;
            s=0;
        }
    }
    res[0]='1'+s;
    return res;
}

int main(){
    int s = 20;
    int d = 3;
    cout<<smallestNumber(s,d);
    return 0;
}