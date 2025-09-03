#include <bits/stdc++.h> 
using namespace std;
void perm(string s,int i,int j,vector<string>& res){
    if(i==j){
        res.push_back(s);
        return;
    }
    for(int a=i;a<=j;a++){
        swap(s[a],s[i]);
        perm(s,i+1,j,res);
        swap(s[a],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> res;
    int n = s.length();
    perm(s,0,n-1,res);
    return res;
}
int main(){
    string s ="abc";
    vector<string> res = findPermutations(s);
    for(string r:res) cout<<r<<endl;
    return 0;
}