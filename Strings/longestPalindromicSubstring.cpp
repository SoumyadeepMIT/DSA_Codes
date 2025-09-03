#include <bits/stdc++.h> 
using namespace std;
string longestPalindrome(string s) {
    // code here
    int n = s.length();
    int ml = 0;
    int st = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=1;j++){
            int lo = i;
            int hi = i+j;
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                int cl = hi-lo+1;
                if(cl>ml){
                    ml = cl;
                    st = lo;
                }
                lo--;
                hi++;
            }
        }
    }
    return s.substr(st,ml);
}
int main(){
    string s = "forgeeksskeegfor";
    cout<<longestPalindrome(s);
    return 0;
}