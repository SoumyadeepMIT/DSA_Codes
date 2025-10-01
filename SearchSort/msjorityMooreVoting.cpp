#include <bits/stdc++.h> 
using namespace std;
int majorityElement(vector<int>& arr) {
    // code here
    int votes = 0;
    int cand = -1;
    for(int n:arr){
        if(votes==0){
            cand = n;
            votes = 1;
        }
        else if(cand == n){
            votes++;
        }
        else{
            votes--;
        }
    }
    int c = 0;
    for(int n:arr){
        if(cand == n) c++;
    }
    return c>(arr.size()/2)?cand:-1;
}
int main(){
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout<<majorityElement(arr);
    return 0;
}