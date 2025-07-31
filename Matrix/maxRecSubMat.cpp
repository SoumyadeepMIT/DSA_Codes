#include <bits/stdc++.h>
using namespace std;
int histRec(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    int ma = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            int height = arr[st.top()];
            st.pop();
            if(st.empty()) ma = max(ma,height*i);
            else ma = max(ma, height* (i-st.top()-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int height = arr[st.top()];
        st.pop();
        if(st.empty()) ma = max(ma,height*n);
        else ma = max(ma, height* (n-st.top()-1));
    }
    return ma;
}
int maxArea(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(m,0);
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) prev[j]++;
            else prev[j] = 0;
        }
        res = max(res,histRec(prev));
    }
    return res;
}
int main(){
    vector<vector<int>> mat = 
        {{0,1,1,0},
         {1,1,1,1},
         {1,1,1,1},
         {1,1,0,0}};
         
    cout << maxArea(mat) << endl;
    
    return 0;
}