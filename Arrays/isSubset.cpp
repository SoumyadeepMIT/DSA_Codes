#include <bits/stdc++.h>
using namespace std;
bool isSubset(vector<int> &a, vector<int> &b) {
    // Your code here
    unordered_map<int,int> um;
    for(int n:a){
        um[n]++;
    }
    for(int n:b){
        if(um[n]==0) return false;
        um[n]--;
    }
    return true;
}
int main(){
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b = {11, 3, 7, 1, 7};
    if(isSubset(a,b)) cout<<"It is a subset";
    else cout<<"not a subset";
    return 0;
}