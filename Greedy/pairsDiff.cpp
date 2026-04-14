#include <bits/stdc++.h>
using namespace std;
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
    // Your code goes here
    sort(arr, arr+N);
    int res = 0;
    for(int i=N-1;i>=1;i--){
        if((arr[i]-arr[i-1])<K){
            res += arr[i] + arr[i-1];
            i--;
        }
    }
    return res;
}
int main() {
    int arr[] = {3, 5, 10, 15, 17, 12};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K) << endl; // Output: 37
    return 0;
}