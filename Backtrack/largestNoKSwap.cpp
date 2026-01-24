#include <bits/stdc++.h>
using namespace std;
string solve(string& s, int k){
    if(k==0) return s;
    string ans = s;
    int n = s.length();
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(s[i]<s[j]){
                swap(s[i], s[j]);
                ans = max(ans, solve(s, k-1));
                swap(s[i],s[j]);
            }
        }
    }
    return ans;
}
string findMaximumNum(string& s, int k) {
    // code here.
    return solve(s, k);
}
int main() {
    string s = "254";
    int k = 1;
    string result = findMaximumNum(s, k);
    cout << "The largest number after " << k << " swaps is: " << result << endl;
    return 0;
}