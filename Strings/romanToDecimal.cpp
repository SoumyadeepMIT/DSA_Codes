#include <bits/stdc++.h> 
using namespace std;
int romanToDecimal(string &s) {
    // code here
    unordered_map<char,int> um = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    int res = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(i<n-1 && um[s[i]]<um[s[i+1]]){
            res += (um[s[i+1]]-um[s[i]]);
            i++;
        }
        else{
            res += um[s[i]];
        }
    }
    return res;
}
int main(){
    string s="MCMIV";
    cout<<romanToDecimal(s);
    return 0;
}