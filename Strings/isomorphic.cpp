#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(string &s1, string &s2) {
    // code here
    unordered_map<char,char> um1;
    unordered_map<char,char> um2;
    for(int i=0;i<s1.length();i++){
        if(um1.find(s1[i])!=um1.end()){
            if(um1[s1[i]]!=s2[i]) return false;
        }
        else{
            um1[s1[i]] = s2[i];
        }
        if(um2.find(s2[i])!=um2.end()){
            if(um2[s2[i]]!=s1[i]) return false;
        }
        else{
            um2[s2[i]] = s1[i];
        }
    }
    return true;
}
int main(){
    string s1 = "aab", s2 = "xxy";
    if(areIsomorphic(s1,s2)) cout<<"Yes";
    else cout<<"No";
    return 0;
}