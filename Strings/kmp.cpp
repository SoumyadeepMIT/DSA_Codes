#include <bits/stdc++.h> 
using namespace std;
int getLPSLength(string &s) {
    // code here
    vector<int> lps(s.length(),0);
    int res = 0;
    for(int i=1;i<s.length();i++){
        int prev = lps[i-1];
        while(prev>0 && s[prev]!=s[i]){
            prev = lps[prev-1];
        }
        lps[i] = prev + (s[i]==s[prev]?1:0);
    }
    return lps[s.length()-1];
}
int main(){
    string s = "aabcdaabc";
    cout<<getLPSLength(s);
    return 0;
}