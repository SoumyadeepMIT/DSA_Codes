#include <bits/stdc++.h>
using namespace std;
int lcsOf3(string& s1, string& s2, string& s3) {
    // Code here
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
int main() {
    string s1 = "AGGT12";
    string s2 = "12TXAYB";
    string s3 = "12XBA";
    cout << "Length of LCS is " << lcsOf3(s1, s2, s3) << endl;
    return 0;
}