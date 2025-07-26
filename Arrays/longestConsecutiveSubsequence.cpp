#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& arr) {
    // Your code here
    unordered_set<int> us;
    for(int n:arr){
        us.insert(n);
    }
    int res = 0;
    for(int n:arr){
        if(us.find(n-1)==us.end()){
            int c = 0;
            while(us.find(n+c)!=us.end())c++;
            res=max(res,c);
        }
    }
    return res;
}

int main(){
    vector<int> res = {2, 6, 1, 9, 4, 5, 3};
    cout<<longestConsecutive(res);
}