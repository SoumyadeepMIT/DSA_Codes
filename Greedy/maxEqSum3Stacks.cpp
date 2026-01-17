#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int arrSum(vector<int>& arr){
    return accumulate(arr.begin(), arr.end(), 0);
}
int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3) {
    int rem1 = arrSum(S1);
    int rem2 = arrSum(S2);
    int rem3 = arrSum(S3);
    int i=0,j=0,k=0;
    
    while(rem1>=0 && rem2>=0 && rem3>=0){
        if(rem1==rem2 && rem1==rem3) return rem1;
        int maxRem = max(rem1, max(rem2, rem3));
        if(maxRem == rem1) rem1-=S1[i++];
        else if(maxRem == rem2) rem2 -=S2[j++];
        else rem3-=S3[k++];
    }
    return 0;
}

int main() {
    // your code goes here
    int N1 = 5, N2 = 3, N3 = 4;
    vector<int> S1 = {3, 2, 1, 1, 1};
    vector<int> S2 = {4, 3, 2};
    vector<int> S3 = {1, 1, 4, 1};
    cout<<maxEqualSum(N1, N2, N3, S1, S2, S3)<<endl;
    return 0;
}