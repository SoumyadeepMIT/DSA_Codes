#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string s) {
    // code here
    int n = s.length();
    int h = (n+1)/2;
    priority_queue<pair<int, char>> pq;
    vector<int> freq(26,0);
    int mf = 0;
    for(char c:s){
        freq[c-'a']++;
        mf = max(mf,freq[c-'a']);
    }
    if(mf>h) return "";
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push({freq[i], (char)(i+'a')});
        }
    }
    string res = "";
    pair<int, char> prev = pq.top();
    pq.pop();
    res+=prev.second;
    prev.first-=1;
    while(!pq.empty()){
        pair<int, char> curr = pq.top();
        pq.pop();
        res+=curr.second;
        curr.first-=1;
        if(prev.first>0)pq.push(prev);
        prev = curr;
    }
    return res;
}

int main() {
    // your code goes here
    string s;
    s = "aaabc";
    cout<<rearrangeString(s)<<endl;
    return 0;
}