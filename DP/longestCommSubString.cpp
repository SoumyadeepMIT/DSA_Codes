#include <bits/stdc++.h>
using namespace std;
int longCommSubstr(string& s1, string& s2) {
    // your code here
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    int res = 0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}
int main(){
    string s1 = "abcde";
    string s2 = "abfce";
    cout << longCommSubstr(s1, s2) << endl;
    return 0;
}