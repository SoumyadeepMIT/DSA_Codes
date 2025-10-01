#include <bits/stdc++.h> 
using namespace std;
bool poss(vector<int>& rank, int mid,int m){
    int tot = 0;
    for(int n:rank){
        tot += (-1 + sqrt(1 + (8*mid)/n))/2;
    }
    return tot>=m;
}
int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int l = 1;
    int r = 5*m*(m+1);
    while(l<r){
        int mid = l+(r-l)/2;
        if(poss(rank,mid,m)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return r;
}
int main(){
    vector<int> rank = {1,2,3,4};
    cout<<minCookTime(rank,11);
    return 0;
}