#include <bits/stdc++.h>
using namespace std;
int findSubString(string& str) {
    // code here
    unordered_set<char> st;
    for(char c:str) st.insert(c);
    int sz = st.size();
    int l=0,r=0;
    int res = str.length();
    vector<int> freq(26,0);
    int d = 0;
    while(r<str.length()){
        if(freq[str[r]-'a']==0) d++;
        freq[str[r]-'a']++;
        while(d==sz){
            res=min(res,r-l+1);
            freq[str[l]-'a']--;
            if(freq[str[l]-'a']==0) d--;
            l++;
        }
        r++;
    }
    return res;
}
int main(){
    string s = "aabcbcdbca";
    cout<<findSubString(s);
    return 0;
}