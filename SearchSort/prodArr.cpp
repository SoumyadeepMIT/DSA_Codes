#include <bits/stdc++.h> 
using namespace std;
vector<int> productExceptSelf(vector<int>& arr) {
    // code here
    int prod = 1;
    int z = 0;
    for(int n:arr){
        if(n==0) z++;
        else prod*=n;
    }
    vector<int> res;
    for(int n:arr){
        if(z>1){
            res.push_back(0);
        }
        else{
            if(n==0){
                res.push_back(prod);
            }
            else{
                if(z==1) res.push_back(0);
                else res.push_back(prod/n);
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);
    for(int n: res) cout<<n<<" ";
    return 0;
}