#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>& merged, int i, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int large = i;
    if(l<n && merged[l]>merged[large]) large = l;
    if(r<n && merged[r]>merged[large]) large = r;
    if(large!=i){
        swap(merged[large], merged[i]);
        heapify(merged, large, n);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // your code here
    vector<int> merged;
    for(int n:a) merged.push_back(n);
    for(int n:b) merged.push_back(n);
    int tot = n+m;
    int si = tot/2 -1;
    for(int i=si;i>=0;i--){
        heapify(merged, i, tot);
    }
    return merged;
}
int main(){
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> res = mergeHeaps(a, b, a.size(), b.size());
    for(int n:res){
        cout<<n<<" ";
    }
    return 0;
}