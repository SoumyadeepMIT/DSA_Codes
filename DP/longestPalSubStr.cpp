#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int st = 0;
    int maxv = 1;
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
        if(i+1<n && s[i] == s[i+1]){
            dp[i][i+1] = 2;
            if(maxv<dp[i][i+1]){
                maxv= dp[i][i+1];
                st = i;
                maxv = 2;
            }
        }
    }
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            if(dp[i+1][j-1]!=0 && s[i] == s[j]){
                dp[i][j]=dp[i+1][j-1] + 2;
                if(maxv<l){
                    maxv = l;
                    st = i;
                }
            }
        }
    }
    return s.substr(st, maxv);
}
int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}