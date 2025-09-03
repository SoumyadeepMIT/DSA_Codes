#include <bits/stdc++.h> 
using namespace std;
int minFlips(string& s) {
    // code here
    int n = s.length();
    int flips1 = 0;
    int prev = (int)(s[0]-'0');
    for(int i=1;i<n;i++){
        if((int)(s[i]-'0')!=(1-prev)) flips1++;
        prev = 1-prev;
    }
    int flips2 = 1;
    prev = 1 - (int)(s[0]-'0');
    for(int i=1;i<n;i++){
        if((int)(s[i]-'0')!=(1-prev)) flips2++;
        prev = 1-prev;
    }
    return min(flips1,flips2);
}
int main(){
    string s = "0001010111";
    cout<<minFlips(s);
    return 0;
}