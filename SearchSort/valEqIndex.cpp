#include <bits/stdc++.h> 
using namespace std;
vector<int> valueEqualToIndex(vector<int>& arr) {
    // code here
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == i+1) res.push_back(arr[i]);
    }
    return res;
}
int main(){
    vector<int> arr = {15, 2, 45, 4 , 7};
    vector<int> res = valueEqualToIndex(arr);
    for(int n:res) cout<<n<<" ";
}