#include <bits/stdc++.h>
using namespace std;
string rearrangeString(string s) {
    // code here
    priority_queue<pair<int,char>> pq;
    vector<int> freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push({freq[i],i+'a'});
        }
    }
    auto temp = pq.top();
    pq.pop();
    string res = "";
    res += temp.second;
    temp.first--;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        res+=top.second;
        if(temp.first>0){
            pq.push(temp);
        }
        temp = {top.first-1,top.second};
    }
    if(res.length()!=s.length()) return "";
    return res;
}
int main(){
    string s = "aaabc";
    cout<<rearrangeString(s);
    return 0;
}