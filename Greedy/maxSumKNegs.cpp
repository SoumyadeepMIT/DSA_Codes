#include <bits/stdc++.h>
using namespace std;
long long int maximizeSum(long long int a[], int n, int k) {
    // Your code goes here
    sort(a, a+n);
    for(int i=0;i<n;i++){
        if(k==0) break;
        if(a[i]<0){
            a[i]*=-1;
            k--;
        }
        else break;
    }
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    k = k%2;
    if(k==0) return sum;
    long long int minv = a[0];
    for(int i=1;i<n;i++){
        if(minv>a[i]) minv = a[i];
    }
    return sum - 2*minv;
}
int main() {
    long long int arr[] = {-2, 0, 5, -1, 2};
    int k = 4;
    cout << maximizeSum(arr,5, k);
    return 0;
}