#include <bits/stdc++.h> 
using namespace std;
void mergeArrays(vector<int>& a, vector<int>& b) {
    // code here
    int n = a.size();
    int m = b.size();
    int l = n-1;
    int r = 0;
    while(l>=0 && r<m){
        if(a[l]>b[r]){
            swap(a[l],b[r]);
        }
        else{
            break;
        }
        l--;
        r++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}
int main(){
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a,b);
    for(int n:a) cout<<n<<" ";
    for(int n:b) cout<<n<<" ";
}