#include <bits/stdc++.h>
using namespace std;
void deleteMid(stack<int>& s) {
    // code here..
    int n = s.size();
    stack<int> st;
    for(int i=0;i<(n/2);i++){
        st.push(s.top());
        s.pop();
    }
    s.pop();
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    deleteMid(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}