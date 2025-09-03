#include <bits/stdc++.h> 
using namespace std;
string removeConsecutiveCharacter(string& s) {
    // code here.
    int n = s.length();
    string str = "";
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])
            str+=s[i];
    }
    str+=s[n-1];
    return str;
}
int main(){
    string s = "aabaa";
    cout<<removeConsecutiveCharacter(s);
    return 0;
}