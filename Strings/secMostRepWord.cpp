#include <bits/stdc++.h>
using namespace std;
string second_repeat(vector<string> &arr, int n){
    // Write your code here.
    if(n==1) return "";
    unordered_map<string,int> um;
    int maxv = 0;
    for(string s:arr) {
        um[s]++;
        maxv = max(maxv, um[s]);
    }
    int m = 0;
    string res = "";
    for(auto it:um){
        if(it.second == maxv) continue;
        if(it.second>m){
            m = it.second;
            res = it.first;
        }
    }
    return res;
}
int main(){
    vector<string> arr = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    cout<<second_repeat(arr, arr.size());
    return 0;
}