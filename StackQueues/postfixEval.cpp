#include <bits/stdc++.h>
using namespace std;
int floorDiv(int a, int b) {
    if (a * b < 0 && a % b != 0)
        return (a / b) - 1;
    return a / b;
}
int evaluatePostfix(vector<string>& arr) {
    // code here
    stack<int> st;
    for(string s: arr){
        if(s == "+"){
            if(st.size()>=2){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = a+b;
                st.push(res);
            }
        }
        else if(s=="-"){
            if(st.size()>=2){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b-a;
                st.push(res);
            } 
        }
        else if(s=="*"){
            if(st.size()>=2){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = a*b;
                st.push(res);
            } 
        }
        else if(s=="/"){
            if(st.size()>=2){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = floorDiv(b,a);
                st.push(res);
            }
        }
        else if(s=="^"){
            if(st.size()>=2){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = pow(b,a);
                st.push(res);
            }
        }
        else{
            st.push(stoi(s));
        }
    }
    return st.top();
}
int main(){
    vector<string> arr = {"2", "3", "^", "4", "5", "*", "+"};
    cout << evaluatePostfix(arr) << endl;
    return 0;
}