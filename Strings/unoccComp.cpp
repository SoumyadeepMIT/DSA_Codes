#include <bits/stdc++.h> 
using namespace std;
int solve(int n, string s) {
    // code here
    vector<bool> freq(26,false);
    vector<bool> used(26,false);
    int res = 0;
    for(char c:s){
        if(freq[c-'A']==false){
            if(n>0){
                n--;
                used[c-'A'] = true;
            }
            else{
                res++;
            }
            freq[c-'A'] = true;
        }
        else{
            if(used[c-'A']) n++;
        }
    }
    return res;
}
int main(){
    string s = "GACCBDDBAGEE";
    int n = 3;
    cout<<solve(n,s);
    return 0;
}