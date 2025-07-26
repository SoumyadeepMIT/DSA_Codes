#include <bits/stdc++.h>
using namespace std;
void fact(vector<int>& res,int n){
    int co = 0;
    for(int i=0;i<res.size();i++){
        int p = res[i]*n;
        p=p+co;
        int d = p%10;
        co = p/10;
        res[i] = d;
    }
    while(co!=0){
        int d = co%10;
        res.push_back(d);
        co /= 10;
    }
}
vector<int> factorial(int n) {
    // code here
    vector<int> res = {1};
    for(int i=2;i<=n;i++){
        fact(res,i);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> res = factorial(88);
    for(int i:res){
        cout<<i<<" ";
    }
}