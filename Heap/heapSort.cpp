#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>& arr,int n, int i){
    int large = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[large]) large = l;
    if(r<n && arr[r]>arr[large]) large = r;
    if(large!=i){
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}
void buildHeap(vector<int>& arr){
    int n = arr.size();
    int si = (n/2)-1;
    for(int i=si;i>=0;i--){
        heapify(arr, n, i);
    }
}
void heapSort(vector<int>& arr) {
    // code here
    int n = arr.size();
    buildHeap(arr);
    for(int i=n-1;i>=0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
int main(){
    vector<int> arr = {5, 3, 8, 4, 1, 2};
    heapSort(arr);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}