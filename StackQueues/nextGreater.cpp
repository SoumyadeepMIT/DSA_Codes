#include <bits/stdc++.h>
using namespace std;
vector<int> nextLargerElement(vector<int>& arr) {
    // code here
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}
int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextLargerElement(arr);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}