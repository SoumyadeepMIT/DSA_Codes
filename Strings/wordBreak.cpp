#include <bits/stdc++.h> 
using namespace std;
bool wordBreak(string &s, vector<string> &dict) {
    // code here
    int n = s.length();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(string w:dict){
            int st = i-w.length();
            if(st>=0 && dp[st] && s.substr(st,w.length())==w){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
int main(){
    string s ="ilikegfg";
    vector<string> dict = {"i", "like", "man", "india", "gfg"};
    if(wordBreak(s,dict)) cout<<"Word break possible";
    else cout<<"Word break not possible";
    return 0;
}