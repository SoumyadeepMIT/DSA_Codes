#include <bits/stdc++.h>
using namespace std;
int getMaxArea(vector<int> &arr) {
    // code here
    stack<int> st;
    int n = arr.size();
    int ma = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            int h = arr[st.top()];
            st.pop();
            int width = st.empty()?i:i-st.top()-1;
            ma = max(ma, h*width);
        }
        st.push(i);
    }
    while(!st.empty()){
        int h = arr[st.top()];
        st.pop();
        int width = st.empty()?n:n-st.top()-1;
        ma = max(ma, h* width);
    }
    return ma;
}
int main(){
    vector<int> arr = {6,2,5,4,5,1,6};
    cout << "Maximum area is: " << getMaxArea(arr) << endl;
    return 0;
}