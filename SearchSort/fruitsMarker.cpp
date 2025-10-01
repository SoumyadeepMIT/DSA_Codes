#include <bits/stdc++.h> 
using namespace std;
bool poss(vector<int>& arr, int M,int m){
    int sum = 0;
    for(int n:arr){
        sum = sum + max(0, n-m);
    }
    return sum>=M;
}
int getMaxMarker(vector<int> &arr, int N, int M)
{
    //  Write your code here.
    int l = 0;
    int r = accumulate(arr.begin(),arr.end(), 0);
    int res = 0;
    while(l<=r){
        int m = (l+r)/2;
        if(poss(arr, M,m)){
            res = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {10,40,30,20};
    cout<<getMaxMarker(arr, arr.size(), 30);
    return 0;
}