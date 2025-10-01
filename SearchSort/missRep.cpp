#include <bits/stdc++.h> 
using namespace std;
vector<int> findTwoElement(vector<int>& arr) {
    // code here
    int n = arr.size();
    int miss, rep;
    for(int i=0;i<n;i++){
        int v = abs(arr[i]);
        if(arr[v-1]>0) arr[v-1] = -arr[v-1];
        else rep = v;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0) miss = i+1;
    }
    return {rep,miss};
}
int main(){
    vector<int> arr = {3,1,3};
    vector<int> res = findTwoElement(arr);
    cout<<res[0]<<" "<<res[1];
    return 0;
}