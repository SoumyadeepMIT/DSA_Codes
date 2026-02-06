#include <bits/stdc++.h>
using namespace std;
bool validateOp(vector<int>& a, vector<int>& b) {
    // code here
    int j = 0;
    stack<int> st;
    for(int i=0;i<a.size();i++){
        st.push(a[i]);
        while(!st.empty() && st.top() == b[j]){
            st.pop();
            j++;
        }
    }
    return j == b.size();
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {4,5,3,2,1};
    if(validateOp(a,b)){
        cout << "Yes, the sequence is valid." << endl;
    }
    else{
        cout << "No, the sequence is not valid." << endl;
    }
    return 0;
}