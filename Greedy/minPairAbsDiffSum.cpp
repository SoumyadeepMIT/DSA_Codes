#include <bits/stdc++.h>
using namespace std;
long long findMinSum(vector<int> &A, vector<int> &B, int n) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long res = 0;
    for(int i=0;i<n;i++){
        res += abs(A[i]-B[i]);
    }
    return res;
}
int main(){
    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};
    int n = A.size();
    cout<<findMinSum(A,B,n);
    return 0;
}