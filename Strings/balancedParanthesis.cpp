#include <bits/stdc++.h> 
using namespace std;
bool isBalanced(string& k) {
    // code here
    stack<char> st;
    for(char c:k){
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else if(c==')'){
            if(!st.empty() && st.top()=='(')st.pop();
            else return false;
        }
        else if(c=='}'){
            if(!st.empty() && st.top()=='{')st.pop();
            else return false;
        }
        else if(c==']'){
            if(!st.empty() && st.top()=='[')st.pop();
            else return false;
        }
    }
    return st.empty();
}
int main(){
    string s="[{()}]";
    if(isBalanced(s)) cout<<"String is balanced";
    else cout<<"String is not balanced";
    return 0;
}