#include <bits/stdc++.h> 
using namespace std;
int getFirst(vector<int>& arr,int x){
    int l=0;
    int r = arr.size() -1;
    int res = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==x){
            res = m;
            r = m-1;
        }
        else if(arr[m]>x) r=m-1;
        else{
            l=m+1;
        }
    }
    return res;
}
int getLast(vector<int>& arr,int x){
    int l=0;
    int r = arr.size() -1;
    int res = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==x){
            res = m;
            l = m+1;
        }
        else if(arr[m]>x) r=m-1;
        else{
            l=m+1;
        }
    }
    return res;
}
vector<int> find(vector<int>& arr, int x) {
    // code here
    vector<int> res = {-1,-1};
    res[0] = getFirst(arr,x);
    res[1] = getLast(arr,x);
    return res;
}
int main(){
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    vector<int> res = find(arr,x);
    cout<<res[0]<<" "<<res[1];
}