#include <bits/stdc++.h> 
using namespace std;
string rle(string s){
    int n = s.length();
    char c = s[0];
    int co = 1;
    string res="";
    for(int i=1;i<n;i++){
        if(s[i]==c){
            co++;
        }
        else{
            res+=to_string(co)+c;
            co=1;
            c=s[i];
        }
    }
    res+=to_string(co)+c;
    return res;
}
string countAndSay(int n) {
    if(n==1){
        return "1";
    }
    string s = countAndSay(n-1);
    string ret = rle(s);
    return ret;
}

int main(){
    cout<<countAndSay(5);
    return 0;
}