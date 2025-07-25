#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int> &arr) {
    // code here
    vector<int> pos;
    vector<int> neg;
    for(int n:arr){
        if(n>=0) pos.push_back(n);
        else neg.push_back(n);
    }
    int i=0,j=0,k=0;
    while(i<pos.size() && j<neg.size()){
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while(i<pos.size()) arr[k++] = pos[i++];
    while(j<neg.size()) arr[k++] = neg[j++];
}
int main(){
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    rearrange(arr);
    for(int n:arr) cout<<n<<" ";
}