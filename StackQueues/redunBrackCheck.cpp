#include <bits/stdc++.h>
using namespace std;
bool checkRedundancy(string &s) {
    // code here
    stack<char> st;
    for(char c:s){
        if(c==')'){
            bool red = true;
            while(!st.empty() && st.top()!='('){
                char v = st.top();
                if(v == '+' || v == '-' || v == '/' || v == '*'){
                    red = false;
                }
                st.pop();
            }
            if(red){
                return true;
            }
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    return false;
}
int main(){
    string s = "(a+b)+((c+d))";
    if(checkRedundancy(s)){
        cout << "Yes, there are redundant brackets." << endl;
    }
    else{
        cout << "No, there are no redundant brackets." << endl;
    }
    return 0;
}