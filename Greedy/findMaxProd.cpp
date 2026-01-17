#include <bits/stdc++.h>
using namespace std;
long long int findMaxProduct(vector<int>& arr) {
    // Write your code here
    int m = 1e9+7;
    long long int prod = 1;
    int cz = 0;
    int cn = 0;
    int cp = 0;
    int maxNeg = INT_MIN;
    for(int n:arr){
        if(n<0){
            cn++;
            prod = (prod*n)%m;
            maxNeg = max(maxNeg, n);
        }
        else if(n>0){
            cp++;
            prod = (prod*n)%m;
        }
        else{
            cz++;
        }
    }
    if(cp==0){
        if(cn==1){
            if(cz==0)return prod;
            else return 0;
        }
        else if(cn==0) return 0;
        else{
            if(cn%2==0) return prod;
            else return prod/maxNeg;
        }
    }
    else{
        if(cn%2==0) return prod;
        else return prod/maxNeg;
    }
}
int main()
{
    vector<int> a = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << findMaxProduct(a);
    return 0;
}