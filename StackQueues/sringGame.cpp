#include <bits/stdc++.h>
using namespace std;
int minValue(string &s, int k) {
    // code here
    vector<int> freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    priority_queue<int> pq;
    for(int i=0;i<26;i++){
        if(freq[i]>0) pq.push(freq[i]);
    }
    while(k>0){
        int n = pq.top();
        pq.pop();
        k--;
        if(n-1!=0)
            pq.push(n-1);
    }
    int res = 0;
    while(!pq.empty()){
        int n = pq.top();
        pq.pop();
        res += (n*n);
    }
    return res;
}
int main(){
    string s = "abccc";
    int k = 1;
    cout<<minValue(s, k);
    return 0;
}