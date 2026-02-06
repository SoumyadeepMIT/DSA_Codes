#include <bits/stdc++.h>
using namespace std;
stack<int> insertAtBottom(stack<int> st, int x) {
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    int x = 0;
    st = insertAtBottom(st, x);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}