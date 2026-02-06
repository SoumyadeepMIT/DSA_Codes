#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string& s) {
    // code here
    stack<char> st;
    for(char c:s){
        if(c == '(' || c=='{' || c == '[') st.push(c);
        else if(c==')'){
            if(st.empty()) return false;
            if(st.top() == '(') st.pop();
            else return false;
        }
        else if(c == '}'){
            if(st.empty()) return false;
            if(st.top()=='{') st.pop();
            else return false;
        }
        else if(c == ']'){
            if(st.empty()) return false;
            if(st.top()=='[') st.pop();
            else return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main() {
    string s = "{([])}";
    if(isBalanced(s)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}