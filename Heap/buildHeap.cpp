#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>& arr, int i, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int small = i;
    if(l<n && arr[l]<arr[small]) small = l;
    if(r<n && arr[r]< arr[small]) small = r;
    if(small != i){
        swap(arr[small], arr[i]);
        heapify(arr, small, n);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here'
    int n = arr.size();
    int si = n/2 - 1;
    for(int i = si;i>=0;i--){
        heapify(arr, i, n);
    }
    return arr;
}

int main(){
    vector<int> arr = {5, 3, 8, 4, 1, 2};
    vector<int> minHeap = buildMinHeap(arr);
    for(int i : minHeap){
        cout << i << " ";
    }
    return 0;
}