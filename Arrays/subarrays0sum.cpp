#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(vector<int>& arr) {
        // Your code here
    unordered_set<int> us;
    int sum = 0;
    for(int n:arr){
        sum+=n;
        if(n==0) return true;
        if(sum==0) return true;
        if(us.find(sum)!=us.end()){
            return true;
        }
        us.insert(sum);
    }
    return false;
}

int main(){
    vector<int> arr = {4, 2, -3, 1, 6};
    cout<<subArrayExists(arr);
    return 0;
}