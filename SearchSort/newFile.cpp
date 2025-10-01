#include <bits/stdc++.h> 
using namespace std;
bool findPair(vector<int> &arr, int x) {
    // code here
    unordered_set<int> us;
    for(int n:arr){
        if(us.find(n+x)!=us.end() || us.find(n-x)!=us.end()) return true;
        us.insert(n);
    }
    return false;
}
int main(){
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    int x = 78;
    if(findPair(arr,x)) cout<<"Pair found";
    else cout<<"No pairs";
    return 0;
}