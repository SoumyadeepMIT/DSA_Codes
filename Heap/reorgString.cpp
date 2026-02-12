#include <bits/stdc++.h> 
using namespace std;
string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for(char c: s){
        freq[c-'a']++;
    }
    priority_queue<pair<int, char>> pq;
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push({freq[i], (char)(i+'a')});
        }
    }
    auto prev = pq.top();
    int f = prev.first;
    string res = "";
    if(f>(s.length() + 1)/2) return res;
    res+=prev.second;
    pq.pop();
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        res+=curr.second;
        if(prev.first - 1>0){
            pq.push({prev.first-1, prev.second});
        }
        prev = curr;
    }
    return res;
}
int main(){
    string s = "aab";
    cout<<reorganizeString(s);
}