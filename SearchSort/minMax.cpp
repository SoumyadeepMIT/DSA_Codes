#include <bits/stdc++.h> 
using namespace std;
pair<int, int> getMinMax(vector<int> arr) {
    // code here
    int minv = INT_MAX;
    int maxv = INT_MIN;
    for(int n:arr){
        minv = min(n,minv);
        maxv = max(n,maxv);
    }
    return {minv,maxv};
}
int main(){
    vector<int> arr = {3, 2, 1, 56, 10000, 167};
    pair<int, int> p = getMinMax(arr);
    cout<<p.first<<" "<<p.second;
}