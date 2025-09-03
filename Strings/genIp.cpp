#include <bits/stdc++.h>
using namespace std;
bool isValid(string &s){
    int n = s.length();
    if(n==1) return true;
    int i = stoi(s);
    if(s[0]=='0' || i>255) return false;
    return true;
}
void gen(string s,vector<string>& res,int k,int ind, string ip){
    string t="";
    if(ind>=s.length()) return;
    if(k==0){
        t = s.substr(ind);
        if(t.length()<=3 && isValid(t)) res.push_back(ip+t);
        return;
    }
    for(int i=ind;i<min(ind+3,(int)s.length());i++){
        t = t+s[i];
        if(isValid(t))
            gen(s,res,k-1,i+1,ip+t+".");
    }
    return;
}
vector<string> generateIp(string s) {
    // code here
    vector<string> res;
    gen(s,res,3,0,"");
    return res;
}
int main(){
    string s = "255678166";
    vector<string> res = generateIp(s);
    for(string ip: res) cout<<ip<<endl;
    return 0;
}