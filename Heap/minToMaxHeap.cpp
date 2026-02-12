#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>& arr, int i, int n){
    int large = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[large]) large = l;
    if(r<n && arr[r]>arr[large]) large = r;
    if(large!=i){
        swap(arr[large], arr[i]);
        heapify(arr, large, n);
    }
}
void convertMinToMaxHeap(vector<int> &arr, int N) {
    int h = (N-2)/2;
    for(int i=h;i>=0;i--){
        heapify(arr, i, N);
    }
}
int main(){
    vector<int> arr = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int n = arr.size();
    convertMinToMaxHeap(arr, n);
    for(int num: arr) cout<<num<<" ";
    return 0;
}