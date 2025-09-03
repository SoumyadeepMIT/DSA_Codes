#include <bits/stdc++.h> 
using namespace std;
int maxSubStr(string str) {
    int c0 = 0;
    int c1 = 0;
    int res = 0;
    for(char c:str){
        if(c=='0') c0++;
        else c1++;
        if(c0==c1) res++;
    }
    if(c0!=c1) return -1;
    return res;
}
int main(){
    string s="0100110101";
    cout<<maxSubStr(s);
    return 0;
}