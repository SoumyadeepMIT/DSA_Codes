#include <bits/stdc++.h> 
using namespace std;
vector<int> comp(string &s){
    int n = s.length();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++){
        int prev = lps[i-1];
        while(prev>0 && s[prev]!=s[i]){
            prev = lps[prev-1];
        }
        lps[i] = prev + (s[prev]==s[i]?1:0);
    }
    return lps;
}
int minChar(string &s) {
    // code here
    string rev = s;
    reverse(rev.begin(),rev.end());
    string l = s+"#"+rev;
    vector<int> lps = comp(l);
    return s.length() - lps.back();
}
int main(){
    string s = "aacecaaaa";
    cout<<minChar(s);
    return 0;
}