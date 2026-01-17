#include<bits/stdc++.h>
using namespace std;
string chooseandswap(string str) {
    // Code Here
    vector<int> fo(26,-1);
    for(int i=0;i<str.length();i++){
        if(fo[str[i]-'a']==-1) fo[str[i]-'a']=i;
    }
    bool poss = false;
    char c1,c2;
    for(int i=0;i<str.length();i++){
        int c = str[i]-'a';
        for(int j=0;j<c;j++){
            if(fo[j]>fo[c]){
                poss = true;
                c1 = str[i];
                c2 = (char)(j+'a');
                break;
            }
        }
        if(poss) break;
    }
    if(!poss) return str;
    for(int i=0;i<str.length();i++){
        if(str[i]==c1) str[i]=c2;
        else if(str[i]==c2) str[i] = c1;
    }
    return str;
}
int main(){
    string s = "ccad";
    cout<<chooseandswap(s);
}