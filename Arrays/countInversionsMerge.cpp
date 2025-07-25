#include<bits/stdc++.h>
using namespace std;

int solveAndMerge(vector<int>& arr,int l,int m,int r){
    int nl = m-l+1;
    int nr = r-m;
    vector<int> left(nl);
    vector<int> right(nr);
    for(int i=0;i<nl;i++){
        left[i] = arr[i+l];
    }
    for(int i=0;i<nr;i++){
        right[i] = arr[m+1+i];
    }
    int k = l;
    int inv = 0;
    int i=0,j=0;
    while(i<nl && j<nr){
        if(right[j]>=left[i]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
            inv+=(nl-i);
        }
    }
    while(i<nl){
        arr[k++] = left[i++];
    }
    while(j<nr){
        arr[k++] = right[j++];
    }
    return inv;
}
int solve(vector<int>& arr,int l,int r){
    int res = 0;
    if(l<r){
        int m = (l+r)/2;
        res+=solve(arr,l,m);
        res+=solve(arr,m+1,r);
        res+=solveAndMerge(arr,l,m,r);
    }
    return res;
}
int inversionCount(vector<int> &arr) {
    // Code Here
    return solve(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr = {4, 3, 2, 1};
    
    cout << inversionCount(arr);
    return 0;
}