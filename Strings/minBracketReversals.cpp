#include <bits/stdc++.h> 
using namespace std;
int countMinReversals(string s) {
    // code here
    int n = s.length();
    if(n%2!=0) return -1;
    stack<char> st;
    int rev = 0;
    for(char c:s){
        if(c=='}'){
            if(st.empty()){
                rev++;
                st.push('{');
            }
            else{
                st.pop();
            }
        }
        else{
            st.push(c);
        }
    }
    n = st.size();
    rev += (n/2);
    return rev;
}
int main(){
    string s = "}{{}}{{{";
    cout<<countMinReversals(s);
    return 0;
}