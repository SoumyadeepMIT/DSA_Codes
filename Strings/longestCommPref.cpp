#include <bits/stdc++.h> 
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n==1) return strs[0];
    string temp = strs[0];
    for(int i=1;i<n;i++){
        int l1 = temp.length();
        int l2 = strs[i].length();
        int j=0;
        while(j<l1 && j<l2 && temp[j] == strs[i][j]){
            j++;
        }
        temp = temp.substr(0,j);
    }
    return temp;
}
int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);
    return 0;
}