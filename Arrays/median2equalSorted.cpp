#include <bits/stdc++.h>
using namespace std;
double medianOf2(vector<int>& a, vector<int>& b) {
    // Your code goes here
    int l = 0;
    int n = a.size();
    int r = a.size();
    int mid1=0,mid2=0;
    while(l<=r){
        mid1 = (l+r)/2;
        mid2 = n-mid1;
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);
        
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == n ? INT_MAX : b[mid2]);
        if(l1<=r2 && l2<=r1){
            return (double)(max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1>r2){
            r=mid1-1;
        }
        else{
            l=mid1+1;
        }
    }
    return 0;
}
int main(){
    vector<int> a = {-5, 3, 6, 12, 15};
    vector<int> b = {-12, -10, -6, -3, 4};
    cout<<medianOf2(a,b);
}