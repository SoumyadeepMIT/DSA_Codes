#include <bits/stdc++.h>
using namespace std;
bool calc(string& s1, string& s2, string& s3, int i,int j, vector<vector<int>>& dp){
    int k = i+j;
    int n1 = s1.length();
    int n2 = s2.length();
    if(i==n1 && j==n2 && k==s3.length()) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    bool t1 = ((i<n1) && (s1[i] == s3[k])) && calc(s1, s2, s3, i+1, j, dp);
    bool t2 = ((j<n2) && (s2[j] == s3[k])) && calc(s1, s2, s3, i, j+1, dp);
    return dp[i][j] = (t1 || t2);
}
bool isInterleave(string &s1, string &s2, string &s3) {
    // code here
    int n1 = s1.length();
    int n2 = s2.length();
    if((n1 + n2) != s3.length()) return false;
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    return calc(s1, s2, s3, 0, 0, dp);
}
int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}