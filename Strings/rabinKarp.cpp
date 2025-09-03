#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
class Solution {
  public:
    ll hashValue(string st,int val,ll mod){
        int n = st.length();
        ll hash = 0, factor = 1;
        
        for(int i=n-1;i>=0;i--){
            hash = (hash + ((int)(st[i]-'a') * factor)%mod)%mod;
            factor = (factor * val)%mod;
        }
        return hash%mod;
    }
    vector<int> search(string &pat, string &txt) {
        // code here
        ll mod1 = 1e9+7;
        ll mod2 = 1e9+33;
        ll hash1 = hashValue(pat,26,mod1);
        ll hash2 = hashValue(pat,27,mod2);
        int m = pat.length();
        int n = txt.length();
        ll hasht1 = -1;
        ll hasht2 = -1;
        vector<int> res;
        ll mw1 = 1, mw2=1;
        string st = txt.substr(0,m);
        for(int i=0;i<m;i++){
            mw1 = (mw1*26) % mod1;
            mw2 = (mw2*27) % mod2;
        }
        for(int i=0;i<=n-m;i++){
            if(i==0){
                hasht1 = hashValue(st, 26, mod1);
                hasht2 = hashValue(st, 27, mod2);
            }
            else{
                hasht1 = ((hasht1*26)%mod1 - ((txt[i-1]-'a')*mw1)%mod1 + (txt[i+m-1]-'a') + mod1)%mod1;
                hasht2 = ((hasht2*27)%mod2 - ((txt[i-1]-'a')*mw2)%mod2 + (txt[i+m-1]-'a') + mod2)%mod2;
            }
            //cout<<hasht1<<" "<<hasht2<<endl;
            if(hasht1 == hash1 && hasht2==hash2) res.push_back(i);
        }
        return res;
    }
};
int main(){
    Solution s;
    string pat = "geek";
    string txt = "geeksforgeeks";
    vector<int> res = s.search(pat,txt);
    for(int i:res) cout<<i<<" ";
}