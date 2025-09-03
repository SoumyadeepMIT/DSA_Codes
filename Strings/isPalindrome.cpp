#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string& s) {
    // code here
    int l = 0;
    int r = s.length() - 1;
    while(l<r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}
int main(){
    string s = "abba";
    if(isPalindrome(s)) cout<<"Its a palindrome";
    else cout<<"Not palindrome";
    return 0;
}