#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerEle(vector<int>& arr) {
    //  code here
    stack<int> st;
    int n = arr.size();
    vector<int> res (n, -1);
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i] = -1;
        }
        else{
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}
int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> res = nextSmallerEle(arr);
    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}