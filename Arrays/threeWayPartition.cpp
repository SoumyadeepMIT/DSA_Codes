#include <bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
    int n = arr.size();
    int k = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<a){
            swap(arr[i],arr[k]);
            k++;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=a && arr[i]<=b){
            swap(arr[i],arr[k]);
            k++;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>b){
            swap(arr[i],arr[k]);
            k++;
        }
    }
}
int main(){
    vector<int> arr = {1, 4, 3, 6, 2, 1};
    int a = 1, b = 3;
    threeWayPartition(arr, a, b);
    for(int n:arr) cout<<n<<" ";
    return 0;
}