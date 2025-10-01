#include <bits/stdc++.h> 
using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k) {
    // code here
    int n = a.size();
    int m = b.size();
    if(n>m) return kthElement(b,a,k);
    int left = max(0,k-m), right = min(k,n);
    while(left<=right){
        int c1 = (left+right)/2;
        int c2 = k-c1;
        int al = c1>0?a[c1-1]:INT_MIN;
        int bl = c2>0?b[c2-1]:INT_MIN;
        int ar = c1<n?a[c1]:INT_MAX;
        int br = c2<m?b[c2]:INT_MAX;
        if(al<=br && bl<=ar) return max(al,bl);
        else if(al>br){
            right = c1-1;
        }
        else if(bl>ar) left = c1+1;
    } 
    return -1;
}
int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout<<kthElement(a,b,k);
    return 0;
}