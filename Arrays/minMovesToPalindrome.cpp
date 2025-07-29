#include <bits/stdc++.h>
using namespace std;
int minMoves(string&s, int l,int r){
    if(s.length()==0) return 0;
    int t = l;
    while(s[t]!=s[r]){
        t++;
    }
    if(t==r){
        int m = (r/2);
        s.erase(r,1);
        return m + minMoves(s,0,s.length()-1);
    }
    s.erase(t,1);
    s.erase(s.length()-1,1);
    return (t-l) + minMoves(s,0,s.length()-1);
}
int minMovesToMakePalindrome(string s) {
    return minMoves(s,0, s.length()-1);
}
int main(){
    string s= "letelt";
    cout<<minMovesToMakePalindrome(s);
}