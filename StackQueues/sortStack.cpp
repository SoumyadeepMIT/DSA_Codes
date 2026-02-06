#include <bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &st) {
    // code here
    stack<int> temp;
    while(!st.empty()){
        int t = st.top();
        st.pop();
        while(!temp.empty() && t<temp.top()){
            st.push(temp.top());
            temp.pop();
        }
        temp.push(t);
    }
    swap(st, temp);
}
int main(){
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);
    sortStack(st);
    cout << "Sorted numbers are:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}