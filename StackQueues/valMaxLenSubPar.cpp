#include <bits/stdc++.h>
using namespace std;
int maxLength(string& s) {
    // code here
    stack<int> st;
    st.push(-1);
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                res = max(res, i-st.top());
            }
        }
    }
    return res;
}

int main(){
    string s = "((())()(()((";
    cout << "Maximum length of valid parentheses substring is: " << maxLength(s) << endl;
    return 0;
}