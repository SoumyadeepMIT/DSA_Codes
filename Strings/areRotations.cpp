#include <bits/stdc++.h>
using namespace std;
bool areRotations(string &s1, string &s2) {
    // code here
    s2 = s2 + s2;
    size_t idx = s2.find(s1);
    if(idx != string::npos) return true;
    return false;
}
int main(){
    string s1 = "abcd", s2 = "cdab";
    if(areRotations(s1,s2)) cout<<"Its a rotation";
    else cout<<"Not a rotation";
    return 0;
}