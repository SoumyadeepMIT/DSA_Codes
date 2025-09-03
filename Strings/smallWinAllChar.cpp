#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int>& freqs,vector<int>& freqp){
    for(int i=0;i<26;i++){
        if(freqs[i]<freqp[i]) return false;
    }
    return true;
}
string smallestWindow(string &s, string &p) {
    // code here
    vector<int> freqs(26,0);
    vector<int> freqp(26,0);
    for(char c:p) freqp[c-'a']++;
    int l = 0;
    int r = 0;
    int si = -1;
    int minl = s.length();
    while(r<s.length()){
        freqs[s[r]-'a']++;
        while(l<=r && check(freqs,freqp)){
            if(r-l+1<minl){
                minl = r-l+1;
                si=l;
            }
            freqs[s[l]-'a']--;
            l++;
        }
        r++;
    }
    if(si==-1) return "";
    return s.substr(si,minl);
}
int main(){
    string s = "timetopractice";
    string p = "toc";
    cout<<smallestWindow(s,p);
    return 0;
}