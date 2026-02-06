#include <bits/stdc++.h>
using namespace std;
string firstNonRepeating(string &s) {
    // code here
    vector<int> freq(26,0);
    queue<char> qu;
    string res = "";
    for(char c:s){
        if(freq[c-'a']==0){
            qu.push(c);
            
        }
        freq[c-'a']++;
        while(!qu.empty() && freq[qu.front() - 'a']>1){
            qu.pop();
        }
        if(qu.empty()){
            res += '#';
        }
        else{
            res += qu.front();
        }
    }
    return res;
}
int main(){
    string s = "abadbc";
    cout<<firstNonRepeating(s);
    return 0;
}